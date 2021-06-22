//
//  2178-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, visited[101][101];
char a[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void bfs(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    while(!q.empty()) {
        int cx, cy;
        tie(cy, cx) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i]; int ny = cy + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx] || a[ny][nx] != '1') continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push(make_pair(ny, nx));
        }
    }
}
int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    bfs(0, 0);
    cout << visited[n - 1][m - 1];
    return 0;
}
