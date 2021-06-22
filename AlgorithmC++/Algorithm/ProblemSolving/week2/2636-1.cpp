//
//  2636-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, a[101][101], visited[101][101], minC = 10001, cnt, t;
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
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(c[ny][nx] == 'a') {
            c[y][x] = 'c';
            cnt += 1;
            break;
        }
    }
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(c[ny][nx] == 'c' || a[ny][nx] != 1 || visited[ny][nx]) continue;
        if(a[ny][nx] == 1) checkCheese(ny, nx);
    }
}
void melt(int y, int x) {
    c[y][x] = '\0';
    a[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(c[ny][nx] != 'c') continue;
        melt(ny, nx);
    }
}
void solution() {
    do {
        fill(&c[0][0], &c[0][0] + 101 * 101, '\0');
        checkAir(0, 0);
        cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1 && c[i][j] != 'c')
                    checkCheese(i, j);
            }
        }
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(c[i][j] == 'c') {
                    melt(i, j);
                }
            }
        }
        t += 1;
        if(cnt != 0)
            minC = min(minC, cnt);
    } while(cnt);
}
int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    solution();
    
    cout << t - 1 << '\n' << minC;
    return 0;
}
