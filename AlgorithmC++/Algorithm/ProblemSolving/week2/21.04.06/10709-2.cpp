//
//  10709-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int h, w, visited[101][101];
char c[101][101];
queue<pair<int, int>> q;
void bfs() {
    while(!q.empty()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        int nx = x + 1;
        if(nx < w && c[y][nx] != 'c' && visited[y][nx] == -1) {
            visited[y][nx] = visited[y][x] + 1;
            q.push(make_pair(y, nx));
        }
    }
}
int main(void) {
    cin >> h >> w;
    fill(&visited[0][0], &visited[0][0] + 101 * 101, -1);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> c[i][j];
            if(c[i][j] == 'c') {
                q.push(make_pair(i, j));
                visited[i][j] = 0;
            }
        }
    }
    bfs();
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << visited[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
