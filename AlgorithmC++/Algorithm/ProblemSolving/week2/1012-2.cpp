//
//  1012-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/01.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int a[51][51], visited[51][51], t, m, n, res, tempx, tempy, cnt;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
void dfs(int y, int x) {
    if(visited[y][x]) return;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && a[ny][nx])
            dfs(ny, nx);
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int tc = 0; tc < t; tc++) {
        cin >> m >> n >> cnt;
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        for(int i = 0; i < cnt; i++) {
            cin >> tempx >> tempy;
            a[tempy][tempx] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    res += 1;
                }
            }
        }
        cout << res << '\n';
        res = 0;
    }
    return 0;
}
