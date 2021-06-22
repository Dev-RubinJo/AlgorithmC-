#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[5][5][100001];
void input() {
    while(1) {
        int n; cin >> n;
        if(!n) break;
        v.push_back(n);
    }

    memset(dp, -1, sizeof(dp));
}

int power(int from, int to) {
    if(from == 0) return 2;
    if(from == to) return 1;
    if(abs(from - to) == 2) return 4;
    return 3;
}

int func(int y, int x, int idx) {
    if(idx == v.size()) return 0;
    if(dp[y][x][idx] != -1) return dp[y][x][idx];

    int left = func(v[idx], x, idx + 1) + power(y, v[idx]);
    int right = func(y, v[idx], idx + 1) + power(x, v[idx]);
    return dp[y][x][idx] = min(left, right);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    cout << func(0, 0, 0);
    return 0;
}