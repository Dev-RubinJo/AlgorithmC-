//
//  1이 될 때까지.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/09.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
    int n, k, count = 0;
    cin >> n >> k;
    
    while(n != 1) {
        if(n % k == 0)  n /= k;
        else n -= 1;
        count += 1;
    }
    
    cout << count;
    return 0;
}
