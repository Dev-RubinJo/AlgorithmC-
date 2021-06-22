#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[11][11];

void input() {
    cin >> n >> k;
}

int binomialCo(int nn, int r) {
    if(r == 0 || nn == r) {
        return 1;
    }
    int &res = dp[nn][r];
    if(res != 0) return res;
    res = binomialCo(nn - 1, r - 1) + binomialCo(nn - 1, r);
    return res;
}

void func() {
    cout << binomialCo(n, k);
}

int main(void) {
    input();
    func();
    return 0;
}