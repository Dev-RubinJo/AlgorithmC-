#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[1001][1001], a[1001][1001];

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];
}

void func() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j + 1]);
        }
    }
    cout << dp[n - 1][m - 1];
}

int main(void) {
    input();
    func();
    return 0;
}