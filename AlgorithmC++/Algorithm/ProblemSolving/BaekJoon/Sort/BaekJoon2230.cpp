//
//  BaekJoon2230.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/31.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n, first = 0, second = 1;
    int m, ans = 1000000001;
    int a[100001] = {0, };
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n);
    
    while(first < n) {
        int temp = a[second] - a[first];
        if(temp < m) {
            second += 1;
            continue;
        }
        if(temp == m) {
            cout << m;
            return 0;
        }
        ans = min(ans, temp);
        
        first += 1;
    }
    
    cout << ans;
    
    return 0;
}
//    for(int i = 0; i < n; i++) {
//        for(int j = i; j < n; j++) {
//            if(a[j] - a[i] < min && i != j && a[j] - a[i] >= m)
//                min = a[j] - a[i];
//            if(min == m) {
//                cout << m;
//                return 0;
//            }
//        }
//    }
