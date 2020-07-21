//
//  BaekJoon7576.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/21.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n, m; // 여기서는 반대로 지정 n이 가로, m이 세로
int xD[] = {-1, 0, 1, 0};
int yD[] = {0, 1, 0, -1};
int warehouse[1001][1001];
int visited[1001][1001] = {0, };
int maxDate = 0;
queue<pair<int, int> > q;

void bfs() {
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + xD[i];
            int ny = cur.second + yD[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] != 0 || warehouse[nx][ny] == -1) continue;
            visited[nx][ny] = visited[cur.first][cur.second] + 1;
            if(visited[nx][ny] > maxDate) maxDate = visited[nx][ny];
            q.push(make_pair(nx, ny));
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> warehouse[i][j];
            if(warehouse[i][j] == 1) {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            } else if(warehouse[i][j] == -1)
                visited[i][j] = -1;
                
        }
    }

    bfs();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
//            cout << visited[i][j] << " ";
            if(visited[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
//        cout << endl;
    }
    if(maxDate == 0) {
        cout << 0;
    } else {
        cout << maxDate - 1;
    }
    

    return 0;
}
