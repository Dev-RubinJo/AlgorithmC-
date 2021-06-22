/*

어찌보면 자두나무 문제의 심화버전, 3차원 dp를 넘어 4차원 dp다, 탑다운 방식으로 디피를 구성해나간다.

*/


#include <bits/stdc++.h>
using namespace std;
int n, m, c, dp[51][51][51][51], mod = 1000007, arr[51][51];

void input() {
    cin >> n >> m >> c;
    for(int i = 0; i < c; i++) {
        int y, x; cin >> y >> x;
        arr[y - 1][x - 1] = i + 1;
    }
    memset(dp, -1, sizeof(dp));
}

int dfs(int y, int x, int cnt, int prev) {
    if(y >= n || x >= m) return 0;
    if(y == n - 1 && x == m - 1) {
        if(cnt == 0 && !arr[y][x]) return 1;
        if(cnt == 1 && arr[y][x] > prev) return 1;
        return 0;
    }
    int &res = dp[y][x][cnt][prev];
    if(~res) return res;
    res = 0;
    if(!arr[y][x]) {
        res = (dfs(y + 1, x, cnt, prev) + dfs(y, x + 1, cnt, prev)) % mod;
    } else if(arr[y][x] > prev) {
        res = (dfs(y + 1, x, cnt - 1, arr[y][x]) + dfs(y, x + 1, cnt - 1, arr[y][x])) % mod;
    }
    return res;
}

void func() {
    for(int i = 0; i <= c; i++) {
        cout << dfs(0, 0, i, 0) << " ";
    }
}

int main(void) {
    input();
    func();
    return 0;
}