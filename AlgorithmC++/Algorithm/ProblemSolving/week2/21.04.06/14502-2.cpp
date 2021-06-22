//
//  14502-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, a[9][9], visited[9][9], maxC;
vector<pair<int, int> > v;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void virus(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(a[ny][nx] || nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx]) continue;
        virus(ny, nx);
    }
}
void safe() {
    fill(&visited[0][0], &visited[0][0] + 9 * 9, 0);
    for(int c = 0; c < n; c++) {
        for(int b = 0; b < m; b++) {
            if(a[c][b] == 2 && !visited[c][b]) virus(c, b);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] || a[i][j]) continue;
            cnt += 1;
        }
    }
    maxC = max(maxC, cnt);
}
int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(!a[i][j]) v.push_back(make_pair(i, j));
        }
    }
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < j; k++) {
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
                safe();
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
            }
        }
    }
    cout << maxC;
    return 0;
}
