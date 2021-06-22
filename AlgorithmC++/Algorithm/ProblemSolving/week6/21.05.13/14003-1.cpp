#include <bits/stdc++.h>
using namespace std; 

int n, lis[1000004], len, num;
pair<int, int> ans[1000004];
stack<int> st; 

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
        scanf("%d", &num);
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
        if(*lowerPos == 0) len++;
        *lowerPos = num;  
        ans[i].first = _pos;
        ans[i].second = num; 
    }
	printf("%d\n", len);
    //for(int i = 0; i < n; i++)printf("%d %d\n", ans[i].first, ans[i].second);
    for(int i = n - 1; i >= 0; i--){
        if(ans[i].first == len - 1){
            st.push(ans[i].second); len--;
        }
    }
    while(st.size()){
        printf("%d ", st.top());st.pop();
    } 
	return 0;
}