#include <bits/stdc++.h>
using namespace std;
int n, k, arr[101], dp[100001];

void input() {
    fill(dp, dp + 100001, 987654321);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[arr[i]] = 1;
    }
}

void func() {
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = arr[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }
    if(dp[k] == 987654321) cout << -1;
    else cout << dp[k];
}

int main(void) {
    input();
    func();
    return 0;
}