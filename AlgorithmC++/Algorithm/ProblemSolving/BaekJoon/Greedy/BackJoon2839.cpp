//
//  BackJoon2839.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/23.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int count = 5000;
    for(int i = 0; i <= n / 3; i++) {
        for(int j = 0; j <= n / 5; j++) {
            if((3 * i) + (5 * j) == n) {
                count = min(count, i + j);
            }
        }
    }
    
    if(count == 5000)
        cout << -1;
    else
        cout << count;
    
    return 0;
}
