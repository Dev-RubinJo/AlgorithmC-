#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, arr[101];
ll dp[101][21];
ll answer = 0;

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
                int num = j + arr[i];
                if(num >= 0 && num <= 20) 
                    dp[i][num] += dp[i - 1][j];
                num = j - arr[i];
                if(num >= 0 && num <= 20) 
                    dp[i][num] += dp[i - 1][j];
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