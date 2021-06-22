//
//  1987-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/21.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int r, c, ans;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
bool visited[26];
char m[21][21];
void input() {
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> m[i][j];
}
void func(int y, int x, int cnt) {
    if(visited[m[y][x] - 'A']) return;
    visited[m[y][x] - 'A'] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= c || ny < 0 || ny >= r || visited[m[ny][nx] - 'A']) continue;
        func(ny, nx, cnt + 1);
        visited[m[ny][nx] - 'A'] = 0;
    }
    ans = max(cnt, ans);
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func(0, 0, 1);
    cout << ans;
    return 0;
}
