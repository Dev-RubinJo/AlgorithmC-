//
//  1103.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, m, a[51][51], dp[51][51], ans, flag;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
bool visited[51][51];
string s;
void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'H') a[i][j] = 0;
            else a[i][j] = s[j] - '0';
        }
    }
}
int func(int y, int x) {
    if(y < 0 || y >= n || x < 0 || x >= m || !a[y][x]) return 0;
    if(visited[y][x]) {
        flag = 1;
        return -1;
    }
    if(dp[y][x] != -1) return dp[y][x];
    visited[y][x] = 1;
    dp[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + a[y][x] * dx[i]; int ny = y + a[y][x] * dy[i];
        dp[y][x] = max(dp[y][x], func(ny, nx) + 1);
        if(flag) return -1;
    }
    visited[y][x] = 0;
    return dp[y][x];
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fill(&dp[0][0], &dp[0][0] + 51 * 51, -1);
    input();
    ans = func(0, 0);
    cout << ans;
    return 0;
}
