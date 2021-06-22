//
//  12946.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/07.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {0, 1, -1, 1, -1, 0};
int n, ans, visited[51][51];
char c[51][51];
void dfs(int y, int x, int col) {
    if(visited[y][x] != -1) return;
    visited[y][x] = col;
    ans = max(ans, 1);
    for(int i = 0; i < 6; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || c[ny][nx] != 'X') continue;
        dfs(ny, nx, 1 - col);
        if(visited[ny][nx] == 1) ans = max(ans, 2); // 색이 1이 되는 경우가 있다면 그건 2번째 경우
        if(visited[ny][nx] == col) ans = max(ans, 3); // 현재 색과 연결된 색이 같으면 그 경우는 3개의 색을 칠해야하는 경우
    }
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    fill(&visited[0][0], &visited[0][0] + 51 * 51, -1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(c[i][j] == 'X' && visited[i][j] == -1) {
                dfs(i, j, 0); // 0으로 색을 한번 칠함
            }
        }
    }
    cout << ans;
    return 0;
}
