#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
pair<ll, ll> walk[101], bike[101];
ll tmp1, tmp2, tmp3, tmp4, answer;
ll dp[101][100001];
void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
        walk[i].first = tmp1; walk[i].second = tmp2;
        bike[i].first = tmp3; bike[i].second = tmp4;
    }
}

// int dpfunc(int idx, int time) {
//     if(time > k) {
//         return 0;
//     }
// }

void func() {
    // bottom - up
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            dp[i][walk[i].first] = max(dp[i][walk[i].first], walk[i].second);
            dp[i][bike[i].first] = max(dp[i][bike[i].first], bike[i].second);
        } else {
            for(int j = 0; j <= k; j++) {
                if(!dp[i - 1][j]) continue;
                else {
                    if(k - (j + walk[i].first) >= 0) {
                        dp[i][j + walk[i].first] = max(dp[i][j + walk[i].first], dp[i - 1][j] + walk[i].second);
                    }
                    if(k - (j + bike[i].first) >= 0) {
                        dp[i][j + bike[i].first] = max(dp[i][j + bike[i].first], dp[i - 1][j] + bike[i].second);
                    }
                }
            }
        }
    }
    for(int i = 0; i <= k; i++) {
        answer = max(answer, dp[n][i]);
    }
    cout << answer;
}

int main(void) {
    input();
    func();
    return 0;
}