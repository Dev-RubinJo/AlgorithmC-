#include <bits/stdc++.h>
using namespace std;
int n, a[100001], dp[100001], ans = INT_MIN;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    dp[0] = a[0];
    for(int i = 1; i < n; i++) {
        if(dp[i - 1] + a[i] > a[i]) 
            dp[i] = dp[i - 1] + a[i];
        else 
            dp[i] = a[i];
    }
    for(int i = 0; i < n; i++) {
        cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    cout << "\n\n\n";
    cout << ans;
    return 0;
}