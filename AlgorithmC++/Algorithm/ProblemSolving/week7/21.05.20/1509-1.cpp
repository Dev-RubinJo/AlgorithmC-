#include <bits/stdc++.h>
using namespace std;
string s;
bool is[2501][2501];
int dp[2501];

void palin() {
    for(int i = 1; i <= s.size() - 1; i++) {
        is[i][i] = 1;
    }
    for(int i = 1; i < s.size() - 1; i++) {
        if(s[i] == s[i + 1]) is[i][i + 1] = 1;
    }
    for(int i = 3; i <= s.size() - 1; i++) {
        for(int j = 1; j + i - 1 <= s.size() - 1; j++) {
            int k = i + j - 1;
            if(s[j] == s[k] && is[j + 1][k - 1])
                is[j][k] = 1;
        }
    }
}

void func() {
    palin();
    for(int i = 1; i <= s.size() - 1; i++) {
        dp[i] = 987564321;
        for(int j = 1; j <= i; j++) {
            if(is[j][i]) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    cout << dp[s.size() - 1];
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string tmp;
    cin >> tmp; s = " " + tmp;
    func();
    return 0;
}