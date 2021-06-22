//
//  2589-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/10.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, m, a[51][51], visited[51][51], maxV; // MARK: 최대가 50 X 50이라서 최악의 경우 시간복잡도가 O((n x m) ^ 2)로 생각했다.
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
string s;
void bfs(queue<pair<int, int>> q) {
    while(!q.empty()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || !a[ny][nx] || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            maxV = max(maxV, visited[ny][nx]);
            q.push(make_pair(ny, nx));
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == 'W') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j]) { // MARK: 모든 가능한 경우를 탐색하며 bfs를 돌렸다.
                queue<pair<int, int>> q;
                fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
                visited[i][j] = 1;
                q.push(make_pair(i, j));
                bfs(q);
            }
        }
    }
    cout << maxV - 1;
    return 0;
}
