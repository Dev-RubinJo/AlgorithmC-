#include <bits/stdc++.h>
using namespace std;
int n, dp[1000001];
const int mod = 15746;

void func() {
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
        dp[i] %= mod;
    }
    cout << dp[n];
}

int main(void) {
    cin >> n;
    func();
    return 0;
}