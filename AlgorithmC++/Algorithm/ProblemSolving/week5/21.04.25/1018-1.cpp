//
//  1018-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, ans = INT_MAX;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
bool visited[51][51];
bool a[51][51];
bool w[8][8] = {
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1}
};
bool b[8][8] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}
};
int gow(int y, int x, int by, int bx) {
    int res = 0;
    for(int i = y; i < by; i++) {
        for(int j = x; j < bx; j++) {
            if(a[i][j] != w[i - y][j - x]) res += 1;
        }
    }
    return res;
}
int gob(int y, int x, int by, int bx) {
    int res = 0;
    for(int i = y; i < by; i++) {
        for(int j = x; j < bx; j++) {
            if(a[i][j] != b[i - y][j - x]) res += 1;
        }
    }
    return res;
}

int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char t; cin >> t;
            if(t == 'W') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    for(int i = 0; i <= n - 8; i++) {
        for(int j = 0; j <= m - 8; j++) {
            ans = min(gow(i, j, i + 8, j + 8), ans);
            ans = min(gob(i, j, i + 8, j + 8), ans);
        }
    }
    cout << ans;
    return 0;
}
