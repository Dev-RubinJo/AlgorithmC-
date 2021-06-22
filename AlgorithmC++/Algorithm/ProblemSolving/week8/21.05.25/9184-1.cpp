#include <bits/stdc++.h>
using namespace std;
int a, b, c, dp[21][21][21];

void input() {
    cin >> a >> b >> c;
}

int w(int aa, int bb, int cc) {
    if(aa <= 0 || bb <= 0 || cc <= 0) return 1;
    if(aa > 20 || bb > 20 || cc > 20) return w(20, 20, 20);
    if(aa < bb && bb < cc) {
        if(dp[aa][bb][cc]) return dp[aa][bb][cc];
        else {
            dp[aa][bb][cc] = w(aa, bb, cc - 1) + w(aa, bb - 1, cc - 1) - w(aa, bb - 1, cc);
            return dp[aa][bb][cc];
        }
    } else {
        if(dp[aa][bb][cc]) return dp[aa][bb][cc];
        else {
            dp[aa][bb][cc] = w(aa - 1, bb, cc) + w(aa - 1, bb - 1, cc) + w(aa - 1, bb, cc - 1) - w(aa - 1, bb - 1, cc - 1);
            return dp[aa][bb][cc];
        }
    }
}

void func() {
    while(true) {
        input();
        if(a == -1 && b == -1 && c == -1) return;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    func();
    return 0;
}