//
//  11659-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int a[100004], psum[100004], n, m, c, b;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    
    for(int i = 0; i < m; i++) {
        cin >> b >> c;
        cout << psum[c] - psum[b - 1] << '\n';
    }
    
    return 0;
}
