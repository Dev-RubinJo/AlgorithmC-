//
//  1012-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int t, m, n, bnum, res;
int a[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void dfs(int x, int y) {
    if(!a[y][x]) return;
    a[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n)
            dfs(nx, ny);
    }
}
int main(void) {
    cin >> t;
    for(int tc = 0; tc < t; tc++) {
        cin >> m >> n >> bnum;
        int temp1, temp2;
        for(int b = 0; b < bnum; b++) {
            cin >> temp1 >> temp2;
            a[temp2][temp1] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1) {
                    dfs(j, i);
                    res += 1;
                }
            }
        }
        cout << res << '\n';
        res = 0;
    }
    
    return 0;
}

// 남은 시간 11분 47초
