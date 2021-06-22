#include <bits/stdc++.h>
using namespace std;
int n, k, dp[101][100001], ans;
pair<int, int> arr[101];

void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int w, v; cin >> w >> v;
        arr[i] = {w, v};
    }
}

void func() {
    for(int i = 1; i <= n; i++) {
        for(int j = k; j > 0; j--) {
            if(j - arr[i].first >= 0) {
                dp[i][j] = max(dp[i - 1][j - arr[i].first] + arr[i].second, dp[i - 1][j]);
            } else dp[i][j] = dp[i - 1][j];
        }
    }
    for(int i = 0; i <= k; i++) 
        ans = max(ans, dp[n][i]);
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}