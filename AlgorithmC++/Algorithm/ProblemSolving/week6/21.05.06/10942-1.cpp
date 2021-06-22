#include <bits/stdc++.h>
using namespace std;
int n, a[2001], m, s, e;
bool dp[2001][2001];

void solve() {
    for(int i = 1; i <= n; i++) {
        dp[i][i] = 1;
        if(a[i - 1] == a[i]) 
            dp[i - 1][i] = 1;
    }

    for(int i = 2; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            int k = i + j;
            if(a[j] == a[k] && dp[j + 1][k - 1]) dp[j][k] = 1;
        }
    }
}

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    solve();
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << (int)dp[s][e] << '\n';
    }
}

int main(void) {
    input();
    return 0;
}