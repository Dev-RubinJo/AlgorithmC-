//
//  14497-f.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/08.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
char c[301][301];
int n, m, jx, jy, bx, by, cnt, flag = 0, visited[301][301];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void dfs(int y, int x) {
    if(c[y][x] == '1') {
        c[y][x] = '0';
        visited[y][x] = 1;
        return;
    } else if(c[y][x] == '#') {
        flag = 1;
        return;
    }
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}
void solution() {
    while(!flag) {
        cnt += 1;
        fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
        dfs(jy - 1, jx - 1);
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < m; j++) {
//                cout << visited[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }
}
int main(void) {
    cin >> n >> m;
    cin >> jy >> jx >> by >> bx;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    solution();
    cout << cnt;
    return 0;
}
