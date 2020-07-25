//
//  BaekJoon2133.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/26.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int tiling(int a[], int index) {
    if(index == 2) return a[index] = 3;
    if(index % 2 == 1) return a[index] = 0;
    if(a[index] != 0) return a[index];
    
    a[index] = 3 * tiling(a, index - 2);
    for(int i = 3; i <= index; i++)
        a[index] += 2 * tiling(a, index - i);
    
    return a[index];
}

int main(void) {
    int n;
    int a[31] = {1, };
    cin >> n;
    cout << tiling(a, n);

    return 0;
}


//#include <stdio.h>
//
//int d[1001];
//
//int dp(int x) {
//    if(x == 0) return 1;
//    if(x == 1) return 0;
//    if(x == 2) return 3;
//    if(d[x] != 0) return d[x];
//    int result = 3 * dp(x - 2);
//    for(int i = 3; i <= x; i++) {
//        if(i % 2 == 0)
//            result += 2 * dp(x - i);
//    }
//
//    return d[x] = result;
//}
//
//int main(void) {
//    int n;
//    scanf("%d", &n);
//    printf("%d", dp(n));
//}
