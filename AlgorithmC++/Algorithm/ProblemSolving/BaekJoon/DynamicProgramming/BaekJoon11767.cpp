//
//  BaekJoon11767.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/26.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <iostream>

using namespace std;

long long tiling(long long a[], int index) {
    if(index == 1) return a[index] = 1;
    if(index == 2) return a[index] = 3;
    if(a[index] != 0) return a[index];
    return a[index] = (tiling(a, index - 1) + (2 * tiling(a, index - 2))) % 10007;
}

int main(void) {
    int n;
    long long a[1001] = {0, };
    
    cin >> n;
    cout << tiling(a, n);
    
    return 0;
}
