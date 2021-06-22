#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp[1001][1001];

void input() {
    cin >> a >> b;
}

void lcs() {
    for(int i = 0; i < a.size() + 1; i++) {
        for(int j = 0; j < b.size() + 1; j++) {
            if(!i || !j) dp[i][j] = 0;
            else if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[a.size()][b.size()];
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    lcs();
    return 0;
} 