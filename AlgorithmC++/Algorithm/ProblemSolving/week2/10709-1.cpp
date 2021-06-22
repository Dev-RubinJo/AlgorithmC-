//
//  10709-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/03.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int h, w, visited[101][101];
char a[101][101];
queue<pair<int, int> > q;
void bfs() {
    while(!q.empty()) {
        int x, y;
        tie(y, x) = q.front(); q.pop();
        int nx = x + 1; // MARK: 오른쪽으로만 이동하는게 핵심
        if(nx < 0 || nx >= w || visited[y][nx] != -1) continue;
        visited[y][nx] = visited[y][x] + 1;
        q.push(make_pair(y, nx));
    }
}
int main(void) {
    cin >> h >> w;
    fill(&visited[0][0], &visited[0][0] + 101 * 101, -1);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'c') {
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
