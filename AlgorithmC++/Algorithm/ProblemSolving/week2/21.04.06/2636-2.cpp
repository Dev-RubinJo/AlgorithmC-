//
//  2636-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, a[101][101], t, cnt, minCnt = 10001;
char c[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void checkAir(int y, int x) {
    c[y][x] = 'a';
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || a[ny][nx] || c[ny][nx] == 'a') continue;
        checkAir(ny, nx);
    }
}
void checkCheese(int y, int x) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(c[ny][nx] == 'a') {
            cnt += 1;
            c[y][x] = 'c';
            return;
        }
    }
}
int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    do {
        fill(&c[0][0], &c[0][0] + 100 * 100, '\0');
        checkAir(0, 0);
        cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i][j]) checkCheese(i, j);
        if(cnt != 0) minCnt = min(cnt, minCnt);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1 && c[i][j] == 'c') a[i][j] = 0;
            }
        }
        t += 1;
    } while(cnt != 0);
    cout << t - 1 << '\n' << minCnt;
    return 0;
}
