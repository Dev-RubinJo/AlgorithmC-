//
//  DepthFirstSearch.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/17.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> a[], int visited[], int start) {
    if(visited[start]) return;
    visited[start] = 1;
    cout << start << " ";
    for(int i = 0; i < a[start].size(); i++) {
        int y = a[start][i];
        dfs(a, visited, y);
    }
    
}

int main() {
    int number = 7;
    int visited[7];
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
    
    dfs(a, visited, 1);
    
    return 0;
}
