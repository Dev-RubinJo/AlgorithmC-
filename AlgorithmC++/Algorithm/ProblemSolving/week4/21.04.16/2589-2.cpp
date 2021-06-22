//
//  2589-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/16.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, m, ans, visited[51][51];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char m1[51][51];
int bfs(int y, int x) {
    int cnt = 0;
    queue<pii> q;
    q.push(pii(y, x));
    visited[y][x] = 1;
    while(!q.empty()) {
        int cx, cy;
        tie(cy, cx) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i]; int ny = cy + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx] || m1[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            cnt = max(cnt, visited[ny][nx] - 1);
            q.push(pii(ny, nx));
        }
    }
    return cnt;
}
void func() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(m1[i][j] == 'L') {
                fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
                ans = max(ans, bfs(i, j));
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> m1[i][j];
    func();
    cout << ans;
    return 0;
}
