//
//  P2071.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/01.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int main(void) {
    int test_case;
    int T;
    
    cin >> T;
    
    for(test_case = 1; test_case <= T; ++test_case) {
        double ans = 0; int temp;
        for(int i = 0; i < 10; i++) {
            cin >> temp;
            ans += temp;
        }
        ans /= 10;
        printf("#%d %0.0f\n", test_case, ans);
    }
    
    
    return 0;
}
