//
//  BaekJoon1427.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/12.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    
    int n;
    priority_queue<int> pq;
    scanf("%d", &n);
    
    while(n > 0) {
        pq.push(n % 10);
        n = n / 10;
    }
    
    int range = pq.size();
    
    for(int i = 0; i < range; i++) {
        printf("%d", pq.top());
        pq.pop();
    }
    
    return 0;
}

// 이 문제는 c++에서 큐를 알고 난 다음에 사용하는 것으로 
