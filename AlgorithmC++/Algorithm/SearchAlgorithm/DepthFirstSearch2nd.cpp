//
//  DepthFirstSearch2nd.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/22.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int a[7][10] = {
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int visited[7][10] = {0, };

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int r, int c) {
    if(visited[r][c]) return;
    visited[r][c] = 1;
    cout << r << " " << c << "\n";
    for(int i = 0; i < 4; i++) {
        int nx = dx[i] + r;
        int ny = dy[i] + c;

        if(nx < 0 || nx >= 7 || ny < 0 || ny >= 10) continue;
        if(a[nx][ny] == 0) continue;
        dfs(nx, ny);
    }
}

//void dfs(int r, int c) {
//    stack<pair<int, int> > s;
//    s.push(make_pair(r, c));
//    visited[r][c] = 1;
//    while(!s.empty()) {
//        pair<int, int> cur = s.top(); s.pop();
////        visited[cur.first][cur.second] = 1;
//        cout << cur.first << " " << cur.second << "\n";
//        for(int i = 0; i < 4; i++) {
//            int nx = cur.first + dx[i];
//            int ny = cur.second + dy[i];
//
//            if(visited[nx][ny] || a[nx][ny] == 0) continue;
//            if(nx < 0 || nx >= 7 || ny < 0 || ny >= 10) continue;
//            visited[nx][ny] = 1;
//            s.push(make_pair(nx, ny));
//        }
//    }
//}

int main(void) {
    dfs(0, 0);
    
    return 0;
}
