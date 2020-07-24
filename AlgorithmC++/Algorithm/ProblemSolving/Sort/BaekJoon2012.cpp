//
//  BaekJoon2012.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/24.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; long long result = 0; // 자료형 주의
    int rank[500000];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> rank[i];
    }
    
    sort(rank, rank + n);
    
    for(int i = 0; i < n; i++) {
        result += abs(rank[i] - (i + 1));
    }
    cout << result;
    return 0;
}
