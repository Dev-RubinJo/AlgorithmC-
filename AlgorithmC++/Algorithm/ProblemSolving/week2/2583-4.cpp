//
//  2583-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int m, n, k, a[101][101], visited[101][101], minx, miny, maxx, maxy;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
vector<int> v;
void dfs(int y, int x) {
    k += 1;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || a[ny][nx] || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}
int main(void) {
    cin >> n >> m >> k;
    for(int kk = 0; kk < k; kk++) {
        cin >> minx >> miny >> maxx >> maxy;
        for(int i = 0; i < maxy - miny; i++)
            for(int j = 0; j < maxx - minx; j++)
                a[i + miny][j + minx] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!a[i][j] && !visited[i][j]) {
                k = 0;
                dfs(i, j);
                v.push_back(k);
            }
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}
