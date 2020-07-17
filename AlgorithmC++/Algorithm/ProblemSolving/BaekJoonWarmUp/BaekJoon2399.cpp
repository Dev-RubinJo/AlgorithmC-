//
//  BaekJoon2399.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/18.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    
    int n;
    int x[10000] = {0, };
    long long ans = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += abs(x[i] - x[j]);
        }
    }
    
    cout << ans;
    
    return 0;
}
// 이게 왜 정렬??
