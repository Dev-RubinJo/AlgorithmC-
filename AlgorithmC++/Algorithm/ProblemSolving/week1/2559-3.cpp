//
//  2559-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, k, maxV = INT_MIN, temp;
int a[100002];
int main(void) {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        a[i] = a[i - 1] + temp;
    }
    for(int i = 0; i + k <= n; i++) {
        if(maxV < a[i + k] - a[i]) maxV = a[i + k] - a[i];
    }
    cout << maxV;
    return 0;
}
