//
//  2583-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/03.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int m, n, tc, minx, miny, maxx, maxy, a[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
vector<int> v;
void dfs(int y, int x) {
    a[y][x] = 1;
    tc += 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || a[ny][nx]) continue;
        dfs(ny, nx);
    }
}
int main(void) {
    cin >> n >> m >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> minx >> miny >> maxx >> maxy;
        for(int i = 0; i < maxy - miny; i++) {
            for(int j = 0; j < maxx - minx; j++) {
                a[i + miny][j + minx] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!a[i][j]) {
                tc = 0;
                dfs(i, j);
                v.push_back(tc);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(auto ve: v) cout << ve << " ";
    return 0;
}
