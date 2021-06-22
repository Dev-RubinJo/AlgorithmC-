//
//  1012-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int m, n, k, bx, by, a[51][51], visited[51][51], res, tc;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx] || !a[ny][nx]) continue;
        dfs(ny, nx);
    }
}
int main(void) {
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> m >> n >> k;
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        for(int i = 0; i < k; i++) {
            cin >> bx >> by;
            a[by][bx] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] && !visited[i][j]) {
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
