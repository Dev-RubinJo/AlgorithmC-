//
//  UnionFind.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/19.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int getParent(int parent[], int x) {
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int findParend(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a == b) return 1;
    return 0;
}

int main() {
    int parent[11];
    for(int i = 1; i < 11; i++) {
        parent[i] = i;
    }
    
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
//    unionParent(parent, 4, 5);
    
    unionParent(parent, 5, 8);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);
    unionParent(parent, 2, 7);
    
//    for(int i = 0; i < 11; i++) {
//
//    }
    
    return 0;
}
