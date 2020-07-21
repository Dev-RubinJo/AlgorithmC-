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

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int board[102][102];
int visited[102][102] = {0, };
int xD[] = {-1, 0, 1, 0};
int yD[] = {0, 1, 0, -1};

void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + xD[i];
            int ny = cur.second + yD[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != 1 || visited[nx][ny]) continue;
            visited[nx][ny] = visited[cur.first][cur.second] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            if(temp == '1') board[i][j] = 1;
            else board[i][j] = 0;
        }
    }
    
    bfs();
    cout << visited[n-1][m-1] << endl;
    return 0;
}
// 여기까지가 다시 짜본 코드

// void bfs(int a[][101], int visited[][101], int dx[], int dy[], int x, int y, int n, int m) {
//     queue<pair<int, int> > q;
//     q.push(make_pair(x, y));
//     visited[x][y] = 1;
    
//     while(!q.empty()) {
//         int new_x = q.front().first;
//         int new_y = q.front().second;
//         q.pop();
        
//         for(int i = 0; i < 4; i++) {
//             int next_x = new_x + dx[i];
//             int next_y = new_y + dy[i];
            
//             if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m) {
//                 if(visited[next_x][next_y] == 0 && a[next_x][next_y]) {
//                     q.push(make_pair(next_x, next_y));
//                     visited[next_x][next_y] = visited[new_x][new_y] + 1;
//                 } else if(visited[next_x][next_y] == 0) {
//                     visited[next_x][next_y] = -1;
//                 }
//             }
//         }
//     }
// }

// int main() {
//     int n, m;
//     int miro[101][101];
//     int visited[101][101];
//     int dx[] = {-1, 0, 1, 0};
//     int dy[] = {0, 1, 0, -1};
    
//     for(int i = 0; i < 101; i++) {
//         for(int j = 0; j < 101; j++) {
//             visited[i][j] = 0;
//         }
//     }
    
//     cin >> n >> m;
    
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             char temp;
//             cin >> temp;
//             if(temp == '1')
//                 miro[i][j] = 1;
//             else
//                 miro[i][j] = 0;
//         }
//     }
    
//     bfs(miro, visited, dx, dy, 0, 0, n, m);
    
//     cout << visited[n - 1][m - 1] << endl;
    
//     return 0;
// }
