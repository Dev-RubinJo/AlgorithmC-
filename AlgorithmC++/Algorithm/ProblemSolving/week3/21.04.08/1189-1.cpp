//
//  1189-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/07.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int r, c, k, cnt, res, visited[6][6];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char h[6][6];
void dfs(int y, int x) {
    cout << y << ":" << x << '\n';
    cnt += 1;
    visited[y][x] = 1;
    if(cnt == k) {
        if(y == r - 1 && x == c - 1) res += 1;
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= c || ny < 0 || ny >= r || h[ny][nx] == 'T' || visited[ny][nx]) continue;
        dfs(ny, nx);
        cnt -= 1;
        visited[ny][nx] = 0;
    }
}
int main(void) {
    cin >> r >> c >> k;
    for(int i = r - 1; i >= 0; i--) {
        for(int j = 0; j < c; j++) {
            cin >> h[i][j];
        }
    }
    dfs(0, 0);
    cout << res;
    return 0;
}
