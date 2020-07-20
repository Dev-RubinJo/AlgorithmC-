//
//  BreadthFirstSearch2nd.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/21.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

// void bfs(int visited[][502], int a[][502], int xD[], int yD[], int x, int y, int xSize, int ySize) {
//     queue<pair<int, int> > q;
//     visited[x][y] = 1;
//     q.push(make_pair(x, y));

//     while(!q.empty()) {
//         pair<int, int> current = q.front();
//         q.pop();
//         cout << current.first << " " << current.second << endl;
//         for(int i = 0; i < 4; i++) {
//             int nextX = current.first + xD[i];
//             int nextY = current.second + yD[i];

//             if(nextX < 0 || nextX >= xSize || nextY < 0 || nextY >= ySize) continue;
//             if(visited[nextX][nextY] || a[nextX][nextY] != 1) continue;
//             visited[nextX][nextY] = 1;
//             q.push(make_pair(nextX, nextY));
//         }
//     }
// }

// int main(void) {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // 왼쪽, 위쪽, 오른쪽, 아래쪽 확인하는 방향
//     int xD[] = {-1, 0, 1, 0};
//     int yD[] = {0, 1, 0, -1};

//     int visited[502][502] = {0, };
//     int board[502][502] =
//         {{1,1,1,0,1,0,0,0,0,0},
//         {1,0,0,0,1,0,0,0,0,0},
//         {1,1,1,0,1,0,0,0,0,0},
//         {1,1,0,0,1,0,0,0,0,0},
//         {0,1,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0} };

//     bfs(visited, board, xD, yD, 0, 0, 7, 10);

    

//     return 0;
// }


#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int,int> > Q;
  vis[0][0] = 1; // (0, 0)을 방문했다고 명시
  Q.push(make_pair(0,0)); // 큐에 시작점인 (0, 0)을 삽입.
  while(!Q.empty()){
    pair<int,int> cur = Q.front(); Q.pop();
    cout << '(' << cur.X << ", " << cur.Y << ") -> ";
    for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
      if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
      vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
      Q.push(make_pair(nx,ny));
    }
  }
}