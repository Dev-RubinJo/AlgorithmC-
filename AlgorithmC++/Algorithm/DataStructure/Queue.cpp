//
//  Queue.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/17.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    
    queue<int> q;
    
    q.push(7);
    q.push(5);
    q.push(4);
    q.pop();
    q.push(6);
    q.pop();
    
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}
