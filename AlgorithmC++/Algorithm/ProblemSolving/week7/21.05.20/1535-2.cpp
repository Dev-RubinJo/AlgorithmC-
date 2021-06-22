#include <bits/stdc++.h>
using namespace std;
int n, dp[101][101], l[21], h[21], ans;

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> l[i];
    for(int i = 0; i < n; i++) 
        cin >> h[i];
}

void func() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 100; j++) {
            if(j > l[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - l[i - 1]] + h[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}