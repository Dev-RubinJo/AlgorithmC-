/*
인사를 하면 체력이 줄어들지만 기쁨이 올라간다. 인사를 할수도 있고 안할 수도 있다. -> 냅색문제?
냅색문제라고 생각을 해보자. 그러면 완전탐색으로 모든 경우의 수를 검사했을 때는 2^20의 시간 복잡도가 나온다. 
*/

#include <bits/stdc++.h>
using namespace std;
int n, l[21], h[21], ans;
int dp[101][101];

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
            if(l[i - 1] < j) {
                dp[i][j] = max(h[i - 1] + dp[i - 1][j - l[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            ans = max(ans, dp[i][j]);
        }
    }

    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= 100; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}