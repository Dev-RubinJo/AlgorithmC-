//
//  BaekJoon1926.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/21.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int board[502][502];
int visited[502][502] = {0, };
int xD[] = {-1, 0, 1, 0};
int yD[] = {0, 1, 0, -1};
int maxSize = 0;
int num = 0;

void bfs() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0 || visited[i][j]) continue;
            num++;
            queue<pair<int, int> > q;
            visited[i][j] = 1;
            q.push(make_pair(i, j));
            int area = 0;
            while(!q.empty()) {
                area++;
                pair<int, int> cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + xD[dir];
                    int ny = cur.second + yD[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] != 1 || visited[nx][ny]) continue;
                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                    
                }
            }
            if(maxSize < area) maxSize = area;
        }
    }
        
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    
    bfs();
    
    cout << num << " " << maxSize << endl;
    
    return 0;
}
