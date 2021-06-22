#include <bits/stdc++.h>
using namespace std;
int n, ans, last[1001], a[1001], dp[1001];

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void go(int idx, vector<int> &v) {
    if(idx == -1) return;
    v.push_back(a[idx]);
    go(last[idx], v);
}

void func() {
    fill(last, last + 1001, -1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                last[i] = j;
                ans = i;

                // cout << "i : " << i << " " << "j : " << j << "  " << ans << '\n';
            }    
        }
    }
    vector<int> v;
    go(ans, v);
    cout << v.size() << '\n';
    for(int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
}

int main(void) {
    input();
    func();
    return 0;
}// 숨바꼭질 문제랑 비슷한듯