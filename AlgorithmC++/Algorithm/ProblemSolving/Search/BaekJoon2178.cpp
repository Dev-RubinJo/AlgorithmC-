//
//  BaekJoon2178.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/19.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

void bfs(int a[][101], int visited[][101], int dx[], int dy[], int x, int y, int n, int m) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    
    while(!q.empty()) {
        int new_x = q.front().first;
        int new_y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int next_x = new_x + dx[i];
            int next_y = new_y + dy[i];
            
            if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m) {
                if(visited[next_x][next_y] == 0 && a[next_x][next_y]) {
                    q.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = visited[new_x][new_y] + 1;
                } else if(visited[next_x][next_y] == 0) {
                    visited[next_x][next_y] = -1;
                }
            }
        }
    }
}

int main() {
    int n, m;
    int miro[101][101];
    int visited[101][101];
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            visited[i][j] = 0;
        }
    }
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            if(temp == '1')
                miro[i][j] = 1;
            else
                miro[i][j] = 0;
        }
    }
    
    bfs(miro, visited, dx, dy, 0, 0, n, m);
    
    cout << visited[n - 1][m - 1] << endl;
    
    return 0;
}
