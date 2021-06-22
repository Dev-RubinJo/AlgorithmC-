#include <bits/stdc++.h>
using namespace std;
int n, arr[10001], dp[10001];

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[0] = 0;
}

void func() {
    dp[1] = arr[1];
    dp[2] = arr[2] + arr[1];
    for(int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2] + arr[i], max(dp[i - 1], dp[i - 3] + arr[i - 1] + arr[i]));
    }
    cout << dp[n];
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func();
    return 0;
}