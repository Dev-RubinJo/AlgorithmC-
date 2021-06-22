#include <bits/stdc++.h>
using namespace std;
int n, m, vip[41], dp[41], ans = 1, pre;

void input() {
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> vip[i];
    }
}

void setup() {
    dp[0] = 1; // 이 경우가 있어야 한다. 꼭!
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    for(int i = 5; i <= 40; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

void func() {
    setup();
    for(int i = 0; i < m; i++) {
        ans *= dp[(vip[i] - 1) - pre];
        pre = vip[i];
    }
    ans *= dp[n - pre];

    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}