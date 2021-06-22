//
//  16234-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/18.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, l, r, ans, visited[51][51], a[51][51];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
queue<vector<pii>> q;
void input() {
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
}
void bfs(int y, int x) {
    visited[y][x] = 1;
    vector<pii> v;
    queue<pii> qq;
    v.push_back(pii(y, x));
    qq.push(pii(y, x));
    while(!qq.empty()) {
        int cx, cy;
        tie(cy, cx) = qq.front(); qq.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i]; int ny = cy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx]) continue;
            if(abs(a[ny][nx] - a[cy][cx]) < l || abs(a[ny][nx] - a[cy][cx]) > r) continue;
            visited[ny][nx] = 1;
            qq.push(pii(ny, nx));
            v.push_back(pii(ny, nx));
        }
    }
    q.push(v);
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    while(1) {
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(!visited[i][j]) bfs(i, j);
        if(q.size() == n * n) break;
        while(q.size()) {
            int sum = 0;
            vector<pii> v = q.front(); q.pop();
            for(pii va: v)
                sum += a[va.first][va.second];
            sum /= v.size();
            for(pii va: v)
                a[va.first][va.second] = sum;
        }
        ans += 1;
    }
    cout << ans;
    return 0;
}
