#include <bits/stdc++.h>
using namespace std;
int dp[13][3];
int tc;

void func() {
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[2][2] = 0;
    for(int i = 3; i < 13; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][1];
    }
}

void input() {
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        int tmp; cin >> tmp;
        cout << dp[tmp + 1][0] << '\n';
    }
}

int main(void) {
    func();
    input();
    return 0;
}