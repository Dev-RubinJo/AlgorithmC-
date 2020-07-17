//
//  BaekJoon5648.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/16.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    long long a[1000000];
    long long temp;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        temp = 0;
        long long b = a[i];
        while(b > 0) {
            temp = (b % 10) + (temp * 10);
            b = b / 10;
        }
        a[i] = temp;
    }
    
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
    
    return 0;
}
// 이 문제는 
