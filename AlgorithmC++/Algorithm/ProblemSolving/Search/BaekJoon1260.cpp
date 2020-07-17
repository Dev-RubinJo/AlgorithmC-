//
//  BaekJoon1260.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/18.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void bfs(vector<int> a[], int visitedBFS[], int start) {
    queue<int> q;
    q.push(start);
    visitedBFS[start] = 1;
    
    while(!q.empty()) {
        int b = q.front();
        q.pop();

        cout << b << " ";
        
        for(int i = 0; i < a[b].size(); i++) {
            if(!visitedBFS[a[b][i]]) {
                visitedBFS[a[b][i]] = 1;
                q.push(a[b][i]);
            }
        }
    }
}
void dfs(int visitedDFS[], vector<int> a[], int start) {
    if(visitedDFS[start]) return;
    visitedDFS[start] = 1;
    cout << start << " ";
    for(int i = 0; i < a[start].size(); i++) {
        int y = a[start][i];
        dfs(visitedDFS, a, y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, v;
    vector<int> a[1001];
    int visitedBFS[1001] = {0, };
    int visitedDFS[1001] = {0, };
    
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        a[temp1].push_back(temp2);
        a[temp2].push_back(temp1);
    }
    
    for(int i = 0; i < n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    
    dfs(visitedDFS, a, v);
    cout << "\n";
    bfs(a, visitedBFS, v);
    return 0;
}
