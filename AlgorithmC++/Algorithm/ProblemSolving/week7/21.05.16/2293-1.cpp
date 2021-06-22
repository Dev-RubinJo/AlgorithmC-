#include <bits/stdc++.h>
using namespace std;
int n, k, arr[101], dp[10001];

void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
}

void func() {
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = arr[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - arr[i]];
        }
    }
    // for(int i = 1; i <= k; i++) 
    //     cout << dp[i] << " ";
    cout << dp[k];
}

int main(void) {
    input();
    func();
    return 0;
}