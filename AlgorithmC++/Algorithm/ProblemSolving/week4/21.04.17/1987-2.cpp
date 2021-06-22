//
//  1987-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/17.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int r, c, visited[21][21], ans, a[26];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char m[21][21];
void dfs(int y, int x, int cnt) {
    if(y == r - 1 && x == c - 1) {
        ans = max(ans, cnt);
        return;
    }
    visited[y][x] = 1;
    a[m[y][x] - 'A'] = 1;
    ans = max(ans, cnt);
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= c || ny < 0 || ny >= r || visited[ny][nx] || a[m[ny][nx] - 'A']) continue;
        dfs(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
        a[m[ny][nx] - 'A'] = 0;
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> m[i][j];
    dfs(0, 0, 1);
    cout << ans;
    return 0;
}
