//
//  2468-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/03.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, a[101][101], res, resT, visited[101][101], maxh;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
void dfs(int y, int x, int h) {
    if(visited[y][x]) return;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || a[ny][nx] - h <= 0) continue;
        dfs(ny, nx, h);
    }
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            maxh = max(maxh, a[i][j]);
        }
    }
    for(int h = 0; h <= maxh; h++) {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        resT = 0; // MARK: resT를 쓰면 초기화를 해줘야한다.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] - h > 0 && !visited[i][j]) {
                    dfs(i, j, h);
                    resT += 1;
                }
            }
        }
        res = max(res, resT);
    }
    cout << res;
    return 0;
}
