//
//  2178-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/01/28.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<string> arr, vector<vector<int> > visited, int x, int y, int n, int m) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    queue<pair<int, int> > queue;
    queue.push(make_pair(x, y));
    visited[x][y] = 1;
    
    while (!queue.empty()) {
        pair<int, int> node = queue.front();
        queue.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];
            
            if ((nx < 0 || nx >= n) || (ny < 0 || ny >= m) || visited[nx][ny] >= 1 || arr[nx][ny] - '0' == 0) {
                continue;
            }
            visited[nx][ny] = visited[node.first][node.second] + 1;
            queue.push(make_pair(nx, ny));
        }
    }
    
    return visited[n - 1][m - 1];
}

int main(void) {
    
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    vector<vector<int> > visited(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        arr[i] = a;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
    cout << bfs(arr, visited, 0, 0, n, m);
    
    return 0;
}
