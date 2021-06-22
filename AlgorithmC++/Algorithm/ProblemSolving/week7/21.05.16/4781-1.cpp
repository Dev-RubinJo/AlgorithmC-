#include <bits/stdc++.h>
using namespace std;

int n, carr[5001], c, m, parr[5001], p;
double tmpM, tmpP;
int dp[10001];
int main(void) {
    while(true) {
        cin >> n >> tmpM;
        if(!n && tmpM == 0.00) return 0;
        m = (int) (tmpM * 100 + 0.5);
        fill(dp, dp + 10001, 0);
        for(int i = 0; i < n; i++) {
            cin >> c >> tmpP;
            carr[i] = c; parr[i] = (int)(tmpP * 100 + 0.5);
            dp[parr[i]] = carr[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = parr[i]; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - parr[i]] + carr[i]);
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}