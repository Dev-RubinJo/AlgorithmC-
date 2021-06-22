//
//  15686-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/10.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, m, a[51][51], visited[51][51], minV = 987654321, ans;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
vector<pair<int, int>> chi;

void bfs(queue<pair<int, int>> q) {
    while(!q.empty()) {
        int cy, cx;
        tie(cy, cx) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i]; int ny = cy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx]) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            if(a[ny][nx] == 1) ans += (visited[ny][nx] - 1);
            q.push(make_pair(ny, nx));
        }
    }
}
void solution() {
    for(int i = 1; i < (1 << chi.size()); i++) {
        ans = 0;
        queue<pair<int, int>> q;
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        for(int j = 0; j < chi.size(); j++) {
            if(i & (1 << j)) {
                q.push(chi[j]);
                visited[chi[j].first][chi[j].second] = 1;
            }
            if(q.size() == m) break;
        }
        bfs(q);
        minV = min(minV, ans);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) {
                chi.push_back(make_pair(i, j));
            }
        }
    }
    solution();
    cout << minV;
    return 0;
}
