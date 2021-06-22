//
//  H-CleanAlpha.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/30.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int p, n, res, t;
int a[100000002];
int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> p >> n;
    for(int i = 1; i < n + 1; i++) {
        cin >> t;
        a[i] = a[i - 1] * p + t;
    }
    cout << a[n];    
    return 0;
}
