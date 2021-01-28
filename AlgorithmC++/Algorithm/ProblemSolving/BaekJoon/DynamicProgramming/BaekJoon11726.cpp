//
//  BaekJoon11726.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/26.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int tiling(int a[], int index) {
    if(index == 1) return a[index] = 1;
    if(index == 2) return a[index] = 2;
    if(a[index] != 0) return a[index];
    return a[index] = (tiling(a, index - 1) + tiling(a, index - 2)) % 10007;
}
int main(void) {
    int n;
    int a[1001] = {0, };
    cin >> n;
    cout << tiling(a, n);
    
    return 0;
}
