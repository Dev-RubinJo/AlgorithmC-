//
//  2583-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/19.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
#define y1 xoxoxo
#define time xoxoxo2
int _map[104][104], m, n, k, x1, x2, y1, y2, time;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
vector<int> ret;

int dfs(int y, int x) {
    _map[y][x] = 1;
    int _ret = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || ny >= m || nx < 0 || nx >= n || _map[ny][nx] == 1) continue;
        _ret += dfs(ny, nx);
    }
    return _ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x < x2; x++) {
            for(int y = y1; y < y2; y++) {
                _map[y][x] = 1;
            }
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(_map[i][j] != 1) {
                ret.push_back(dfs(i, j));
            }
        }
    }
    
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for(int _ret: ret) cout << _ret << " ";
    
    return 0;
}
