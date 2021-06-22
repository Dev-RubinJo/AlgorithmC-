//
//  1189-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/10.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int r, c, k, cnt, visited[6][6], ans;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char m[6][6];
void dfs(int y, int x) {
    cnt += 1;
    if(cnt == k) {
        if(y == r - 1 && x == c - 1) ans += 1;
        return;
    }
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= c || ny < 0 || ny >= r || visited[ny][nx] || m[ny][nx] == 'T') continue;
//        visited[ny][nx] = 1;
        dfs(ny, nx);
        visited[ny][nx] = 0;
        cnt -= 1;
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> k;
    for(int i = r - 1; i >= 0; i--)
        for(int j = 0; j < c; j++)
            cin >> m[i][j];
    dfs(0, 0);
    cout << ans;
    return 0;
}
