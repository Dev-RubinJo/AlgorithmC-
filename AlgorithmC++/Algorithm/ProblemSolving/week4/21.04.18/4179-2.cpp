//
//  4179-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/18.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int r, c, fvisited[1001][1001], visited[1001][1001], ans = -1;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char m1[1001][1001];
queue<pii> ji, f;
void input() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> m1[i][j];
            if(m1[i][j] == 'F'){
                f.push(pii(i, j));
                fvisited[i][j] = 1;
            } else if(m1[i][j] == 'J') {
                ji.push(pii(i, j));
                visited[i][j] = 1;
            }
        }
    }
}
void fire() {
    int x, y;
    while(!f.empty()) {
        tie(y, x) = f.front(); f.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r || fvisited[ny][nx] || m1[ny][nx] == '#') continue;
            fvisited[ny][nx] = fvisited[y][x] + 1;
            f.push(pii(ny, nx));
        }
    }
}
void escape() {
    int x, y;
    while(!ji.empty()) {
        tie(y, x) = ji.front(); ji.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(visited[ny][nx] || (visited[y][x] + 1 >= fvisited[ny][nx] && fvisited[ny][nx]) || m1[ny][nx] == '#') continue;
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) {
                ans = visited[y][x];
                return;
            }
            visited[ny][nx] = visited[y][x] + 1;
            ji.push(pii(ny, nx));
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    fire();
    escape();
    if(ans == -1) cout << "IMPOSSIBLE";
    else cout << ans;
    return 0;
}
