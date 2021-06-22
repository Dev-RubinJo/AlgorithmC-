#include <bits/stdc++.h>
using namespace std;
int n, m, arr[51][51], ans, dp[51][51];
bool visited[51][51], flag;
string s;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'H') arr[i][j] = 0;
            else arr[i][j] = s[j] - '0';
        }
    }
    fill(&dp[0][0], &dp[0][0] + 51 * 51, -1);
}

int func(int y, int x) {
    if(y < 0 || y >= n || x < 0 || x >= m || !arr[y][x]) return 0;
    if(visited[y][x]) {
        flag = 1;
        return -1;
    }
    if(dp[y][x] != -1) return dp[y][x];
    dp[y][x] = 0;
    visited[y][x] = 1;
    // cout << y << " " << x << "\n";
    for(int i = 0; i < 4; i++) {
        int ny = y + arr[y][x] * dy[i]; int nx = x + arr[y][x] * dx[i];
        dp[y][x] = max(dp[y][x], func(ny, nx) + 1);
        if(flag) return -1;
    }
    visited[y][x] = 0;
    return dp[y][x];
}

int main(void) {
    input();
    cout << func(0, 0);
    return 0;
}