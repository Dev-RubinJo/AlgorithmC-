//
//  1103.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, m, a[51][51], ans, flag;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
bool visited[51][51];
string s;
void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'H') a[i][j] = 0;
            else a[i][j] = s[j] - '0';
        }
    }
}
void func(int y, int x, int cnt) {
    if(visited[y][x]) {
        flag = 1;
        return;
    }
    if(y < 0 || y >= n || x < 0 || x >= m || !a[y][x]) {
        ans = max(cnt, ans);
        return;
    }
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + a[y][x] * dx[i]; int ny = y + a[y][x] * dy[i];
        func(ny, nx, cnt + 1);
        if(flag) return;
    }
    visited[y][x] = 0;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func(0, 0, 0);
    if(flag) cout << -1;
    else cout << ans;
    return 0;
}
