#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, arr[101];
ll dp[101][21];

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void func() {
    dp[0][arr[0]] = 1;
    for(int i = 1; i < n - 1; i++) {
        for(int j = 0; j < 21; j++) {
            if(dp[i - 1][j] > 0) {
                int number = j + arr[i];
                if(number >= 0 && number <= 20) 
                    dp[i][number] += dp[i - 1][j];
                number = j - arr[i];
                if(number >= 0 && number <= 20)
                    dp[i][number] += dp[i - 1][j];
            }
        }
    }

    cout << dp[n - 2][arr[n - 1]];
}

int main(void) {
    input();
    func();
    return 0;
}


// using namespace std;
// typedef long long ll;
// ll n, dp[101][2][21], arr[101];

// void input() {
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     memset(dp, -1, sizeof(dp));
// }

// ll dpfunc(ll sum, ll cnt, int op) {
//     if(sum < 0 || sum > 20) return 0;
//     if(cnt == n - 2) {
//         if(sum == arr[n - 1]) return 1;
//         else return 0;
//     }
//     ll &res = dp[cnt][op][sum];
//     if(~res) return res;
//     res = dpfunc(sum + arr[cnt], cnt + 1, 0) + dpfunc(sum - arr[cnt], cnt + 1, 1);
//     cout << cnt << " " << op << " " << sum << " " << res << "\n";
//     return res;
// }

// void func() {
//     cout << dpfunc(0, 0, 0);
// }

// int main(void) {
//     input();
//     func();
//     return 0;
// }