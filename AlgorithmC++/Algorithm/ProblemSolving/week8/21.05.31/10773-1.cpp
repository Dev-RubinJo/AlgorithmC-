#include <bits/stdc++.h>
using namespace std;
int k, num, ans;
stack<int> st;

void input() {
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> num;
        if(!num) {
            st.pop();
        } else {
            st.push(num);
        }
    }
}

void func() {
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}