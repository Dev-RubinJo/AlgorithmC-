//
//  2468-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/02.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int a[101][101], temp[101][101], n, maxh, res;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void dfs(int x, int y) {
    temp[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || temp[ny][nx] < 1) continue;
        dfs(nx, ny);
    }
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            maxh = max(maxh, a[i][j]);
        }
    }
    for(int h = 0; h <= maxh; h++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[i][j] = a[i][j] - h;
            }
        }
        int tempRes = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (temp[i][j] > 0) {
                    dfs(j, i);
                    tempRes += 1;
                }
            }
        }
        res = max(res, tempRes);
    }
    cout << res;
    return 0;
}
