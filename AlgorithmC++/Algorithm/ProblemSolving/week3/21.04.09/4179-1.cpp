//
//  4179-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/09.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int r, c, fire[1001][1001], visited[1001][1001];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char mi[1001][1001];
queue<pair<int, int>> f, ji;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c; // MARK: 2) 행과 열을 서로 헷갈려서 계속 여기서 해멨다
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> mi[i][j];
            if(mi[i][j] == 'F') {
                fire[i][j] = 1;
                f.push(make_pair(i, j));
            }
            else if(mi[i][j] == 'J') {
                ji.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }
    while(!f.empty()) {
        int x, y;
        tie(y, x) = f.front(); f.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r || mi[ny][nx] == '#' || fire[ny][nx]) continue;
            fire[ny][nx] = fire[y][x] + 1;
            f.push(make_pair(ny, nx));
        }
    }
    while(!ji.empty()) {
        int x, y;
        tie(y, x) = ji.front(); ji.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(mi[ny][nx] == '#' || visited[ny][nx]) continue; // MARK: 1) 처음에 visited 조건을 제대로 못넣어서 메모리 초과가 떴고,
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) {
                cout << visited[y][x];
                return 0;
            }
            visited[ny][nx] = visited[y][x] + 1;
            if (fire[ny][nx] <= visited[ny][nx] && fire[ny][nx])
                visited[ny][nx] = 0;
            else ji.push(make_pair(ny, nx));
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
//
