//
//  14497-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/12.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
char m1[301][301];
int n, m, visited[301][301], jx, jy, bx, by, cnt, temp, ans, flag;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
queue<pii> q;
void dfs(int y, int x) {
    if(flag) return;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        if(m1[ny][nx] == '#') {
            flag = 1;
            return;
        }
        if(m1[ny][nx] == '1') {
            q.push(pii(ny, nx));
            temp += 1;
            continue;
        }
        dfs(ny, nx);
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> jy >> jx >> bx >> by;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> m1[i][j];
    q.push(pii(jy - 1, jx - 1));
    cnt += 1;
    while(!q.empty()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        dfs(y, x);
        cnt -= 1;
        if(!cnt || flag) {
            cnt = temp;
            temp = 0;
            ans += 1;
        }
        if(flag) break;
    }
    cout << ans;
    return 0;
}
