//
//  BreadthFirstSearch.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/17.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector> // 데이터 저장용

using namespace std;

void bfs(int visited[], vector<int> a[], int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        
        cout << x << endl;
        
        for(int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            if(visited[y] == 0) {
                q.push(y);
                visited[y] = 1;
            }
        }
    }
}

int main() {
    
    int number = 7;
    int visited[7] = {0, };
    
    vector<int> a[8];
    
    a[1].push_back(2);
    a[2].push_back(1);
    
    a[1].push_back(3);
    a[3].push_back(1);
    
    a[2].push_back(3);
    a[3].push_back(2);
    
    a[2].push_back(4);
    a[4].push_back(2);
    
    a[2].push_back(5);
    a[5].push_back(2);
    
    a[4].push_back(5);
    a[5].push_back(4);
    
    a[3].push_back(6);
    a[6].push_back(3);
    
    a[3].push_back(7);
    a[7].push_back(3);
    
    a[6].push_back(7);
    a[7].push_back(6);
    
    bfs(visited, a, 1);
    
    return 0;
}
