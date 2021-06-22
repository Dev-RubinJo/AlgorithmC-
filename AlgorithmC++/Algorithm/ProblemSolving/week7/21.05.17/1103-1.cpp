#include <bits/stdc++.h>
using namespace std;
int n, m, arr[51][51], dp[51][51], ans;
string s;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
bool v[51][51], flag;


void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[i] == 'H') arr[i][j] = 0;
            else arr[i][j] = s[j] - '0';
        }
    }
    fill(&dp[0][0], &dp[0][0] + 51 * 51, -1);
}

int dfs(int y, int x) {
    if(y < 0 || y >= n || x < 0 || x >= m || !arr[y][x]) return 0;
    if(v[y][x]) {
        flag = 1;
        return -1;
    }
    if(dp[y][x] != -1) return dp[y][x];
    v[y][x] = 1;
    dp[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + arr[y][x] * dx[i]; int ny = y + arr[y][x] * dy[i];
        dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
        if(flag) return -1;
    }
    v[y][x] = 0;
    return dp[y][x];
}

int main(void) {
    input();
    cout << dfs(0, 0);
    return 0;
}