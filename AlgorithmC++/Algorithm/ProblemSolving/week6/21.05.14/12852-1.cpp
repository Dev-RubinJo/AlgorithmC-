#include <bits/stdc++.h>
using namespace std;
int n, dp[1000001], trace[1000001], idx;

void input() {
    cin >> n;
    fill(dp, dp + 1000001, 987654321);
    fill(trace, trace + 1000001, -1);
}

void func() {
    dp[1] = 0; trace[1] = 0;
    dp[2] = 1; trace[2] = 1;
    dp[3] = 1; trace[3] = 1;
    for(int i = 4; i <= n; i++) {
        if(dp[i] > dp[i - 1] + 1) {
            dp[i] = min(dp[i], dp[i - 1] + 1);
            trace[i] = i - 1;
        }
        if(!(i % 2) && (dp[i] > dp[i / 2] + 1)) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
            trace[i] = i / 2;
        } 
        if(!(i % 3) && (dp[i] > dp[i / 3] + 1)) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
            trace[i] = i / 3;
        }
    }

    cout << dp[n] << '\n';
    idx = n;
    while(trace[idx] >= 0) {
        cout << idx << " ";
        idx = trace[idx];
    }
}

int main(void) {
    input();
    func();
    return 0;
}