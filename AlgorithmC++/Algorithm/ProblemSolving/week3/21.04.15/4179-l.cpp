//
//  4179-l.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/15.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int r, c, visited[1001][1001], fvisited[1001][1001];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char a[1001][1001];
queue<pii> f, ji;
void fireS() {
    while(!f.empty()) {
        int x, y;
        tie(y, x) = f.front(); f.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r || fvisited[ny][nx] || a[ny][nx] == '#') continue;
            fvisited[ny][nx] = fvisited[y][x] + 1;
            f.push(pii(ny, nx));
        }
    }
}
int func() {
    while(!ji.empty()) {
        int x, y;
        tie(y, x) = ji.front(); ji.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(visited[ny][nx] || a[ny][nx] == '#') continue;
            if(nx < 0 || nx >= c || ny < 0 || ny >= r)
                return visited[y][x];
            if(visited[y][x] + 1 >= fvisited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            ji.push(pii(ny, nx));
        }
    }
    return -1;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'J') {
                ji.push(pii(i, j));
                visited[i][j] = 1;
            }
            else if(a[i][j] == 'F') {
                f.push(pii(i, j));
                fvisited[i][j] = 1;
            }
        }
    }
    fireS();
//    for(int i = 0; i < r; i++) {
//        for(int j = 0; j < c; j++) {
//            cout << fvisited[i][j] << " ";
//        }
//        cout << endl;
//    }
    int cnt = func();
//    for(int i = 0; i < r; i++) {
//        for(int j = 0; j < c; j++) {
//            cout << visited[i][j] << " ";
//        }
//        cout << endl;
//    }
    if(cnt == -1) cout << "IMPOSSIBLE";
    else cout << cnt;
    return 0;
}
