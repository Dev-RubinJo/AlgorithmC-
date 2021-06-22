#include <bits/stdc++.h>
using namespace std;
int tc, n, m;
int dp[31][31];

int binomialCo(int nn, int r) {
    if(r == 0 || nn == r) {
        return 1;
    }
    int &res = dp[nn][r];
    if(res != 0) return res;
    res = binomialCo(nn - 1, r - 1) + binomialCo(nn - 1, r);
    return res;
}

void input() {
    cin >> tc;
    while(tc) {
        tc -= 1;
        cin >> n >> m;
        cout << binomialCo(m, n) << '\n';
    }
}

int main(void) {
    input();

    return 0;
}