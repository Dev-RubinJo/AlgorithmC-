#include <bits/stdc++.h>
using namespace std;
int n, ans;
int A[1001], dp[1001];

void input() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
}

void func() {
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}