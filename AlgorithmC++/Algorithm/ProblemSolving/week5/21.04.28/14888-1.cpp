#include <bits/stdc++.h>
using namespace std;
int n, max_ans = INT_MIN, min_ans = INT_MAX;
vector<int> a, op;
bool v[11];
void func(int cnt, int sum) {
    // cout << sum << '\n';
    if(cnt == n - 1) {
        max_ans = max(max_ans, sum);
        min_ans = min(min_ans, sum);
        return;
    }
    for(int i = 0; i < op.size(); i++) {
        if(v[i]) continue;
        v[i] = 1;
        if(op[i] == 0) func(cnt + 1, sum + a[cnt + 1]);
        else if(op[i] == 1) func(cnt + 1, sum - a[cnt + 1]);
        else if(op[i] == 2) func(cnt + 1, sum * a[cnt + 1]);
        else if(op[i] == 3) func(cnt + 1, sum / a[cnt + 1]);
        v[i] = 0;
    }
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        a.push_back(temp);
    }
        
    for(int i = 0; i < 4; i++) {
        int temp; cin >> temp;
        for(int j = 0; j < temp; j++) {
            op.push_back(i);
        }
    }
    func(0, a[0]);
    cout << max_ans << '\n' << min_ans;
    return 0;
}