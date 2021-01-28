//
//  BaekJoon4179.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/21.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int r, c;
char miro[1001][1001];
int visited[1001][1001] = {0, };
int fireVisited[1001][1001] = {0, };

int xD[] = {-1, 0, 1, 0};
int yD[] = {0, 1, 0, -1};
pair<int, int> startPoint;
queue<pair<int, int> > q;
queue<pair<int, int> > fire;
void bfsForFire() {
    while(!fire.empty()) {
        pair<int, int> cur = fire.front(); fire.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + xD[i];
            int ny = cur.second + yD[i];
            
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(miro[nx][ny] == '#' || fireVisited[nx][ny] != 0) continue;
            fireVisited[nx][ny] = fireVisited[cur.first][cur.second] + 1;
            fire.push(make_pair(nx, ny));
        }
    }
}

void bfs() {
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + xD[i];
            int ny = cur.second + yD[i];
            
            if(miro[nx][ny] == '#' || visited[nx][ny] != 0) continue;
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) { // 이 생각이 중요
                cout << visited[cur.first][cur.second];
                return;
            }
            
            visited[nx][ny] = visited[cur.first][cur.second] + 1;
            if(fireVisited[nx][ny] != 0 && fireVisited[nx][ny] <= visited[nx][ny]) {
                visited[nx][ny] = 0;
            } else {
                q.push(make_pair(nx, ny));
            }
        }
    }
    
    cout << "IMPOSSIBLE";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            char temp;
            cin >> temp;
            miro[i][j] = temp;
            if(temp == 'J') {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
            else if(temp == 'F') {
                fire.push(make_pair(i, j));
                fireVisited[i][j] = 1;
            }
        }
    }
    bfsForFire();

    bfs();

    return 0;
}
