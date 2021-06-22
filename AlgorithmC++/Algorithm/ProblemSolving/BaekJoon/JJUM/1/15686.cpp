//
//  15686.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, m, a[51][51], ans = INT_MAX, visited[51][51];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
vector<pii> chi;
void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) chi.push_back(pii(i, j));
        }
    }
}
int bfs(queue<pii> q) {
    int cnt = 0;
    while(!q.empty()) {
        int x, y;
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;;
            if(a[ny][nx] == 1) cnt += visited[ny][nx] - 1;
            q.push(pii(ny, nx));
        }
    }
    return cnt;
}
void func() {
    for(int i = 1; i < (1 << chi.size()); i++) {
        queue<pii> q;
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        for(int j = 0; j < chi.size(); j++) {
            if(i & (1 << j)) {
                q.push(chi[j]);
                visited[chi[j].first][chi[j].second] = 1;
                if(q.size() == m) break;
            }
        }
        ans = min(ans, bfs(q));
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func();
    cout << ans;
    return 0;
}
