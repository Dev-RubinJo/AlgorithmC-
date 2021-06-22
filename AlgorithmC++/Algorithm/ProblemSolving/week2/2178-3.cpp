//
//  2178-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/03.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
char a[101][101];
int visited[101][101], n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
void bfs(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    while(!q.empty()) {
        int cy, cx;
        tie(cy, cx) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i]; int nx = cx + dx[i];
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
