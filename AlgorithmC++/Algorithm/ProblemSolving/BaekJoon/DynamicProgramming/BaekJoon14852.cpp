//
//  BaekJoon14852.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/26.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

//int tiling(int a[], int index) {
//    if(index == 0) return a[index] = 1;
//    if(index == 1) return a[index] = 2;
//    if(index == 2) return a[index] = 7;
//    if(a[index] != 0) return a[index];
//    int ans = 3 * tiling(a, index - 2) + 2 * tiling(a, index - 1);
//    for(int i = 3; i <= index; i++) {
//        ans += 2 * tiling(a, index - i);
//    }
//
//    return a[index] = ans % 1000000007;
//}

long long int tiling(long long int a[][2], int index) {
    a[0][0] = 0;
    a[1][0] = 2;
    a[2][0] = 7;
    a[2][1] = 1;
    
    for(int i = 3; i <= index; i++) {
        a[i][1] = (a[i - 1][1] + a[i - 3][0]) % 1000000007;
        a[i][0] = (a[i - 2][0] * 3 + a[i - 1][0] * 2 + a[i][1] * 2) % 1000000007;
    }
    
    return a[index][0];
}

int main(void) {
    
    int n;
    long long int a[1000001][2] = {0, };
    
    cin >> n;
    cout << tiling(a, n);
    
    return 0;
}
