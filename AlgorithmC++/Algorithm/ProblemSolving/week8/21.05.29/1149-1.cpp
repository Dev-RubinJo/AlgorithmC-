#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, arr[1001][3], dp[1001][3], ans = INF;

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];
}

void func() {
    for(int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}

int main(void) {
    input();
    func();
    return 0;
}