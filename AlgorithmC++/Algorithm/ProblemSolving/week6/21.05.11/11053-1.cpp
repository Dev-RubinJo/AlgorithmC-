#include <bits/stdc++.h>
using namespace std;
#define prev oxoxoxoxoxo1
int n, a[1001], dp[1001], ans;
int idx[1001], last;
void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void go(int i, vector<int> &v) {
    if(i == -1) return;
    v.push_back(a[i]);
    go(idx[i], v);
}

void solve() {
    fill(idx, idx + 1001, -1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                idx[i] = j;
                // cout << "i : " << i << " " << "j : " << j << '\n';
                if(ans < dp[i]) {
                    ans = dp[i];
                    last = i;
                }
            }
        }
    }
    // vector<int> v;
    // go(last, v);
    // cout << v.size() << '\n';
    // for(int i = v.size() - 1; i >= 0; i--) {
    //     cout << v[i] << " ";
    // }
}

int main(void) {
    input();
    solve();
    return 0;
}
