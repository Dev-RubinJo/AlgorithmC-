//
//  14502-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, a[9][9], cnt, temp[9][9], res, safe;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void countSafe() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(temp[i][j] == 0) safe += 1;
        }
    }
    res = max(res, safe);
    safe = 0;
}
void virus(int y, int x) {
    temp[y][x] = 3;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && !temp[ny][nx]) {
            temp[ny][nx] = 3;
            virus(ny, nx);
        }
    }
}
void dfs() {
    if(cnt == 3) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                temp[i][j] = a[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(temp[i][j] == 2) {
                    virus(i, j);
                }
            }
        }
        countSafe();
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0) {
                cnt += 1;
                a[i][j] = 1;
                dfs();
                cnt -= 1;
                a[i][j] = 0;
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    dfs();
    cout << res;
    return 0;
}
