//
//  13144-f1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, a[100002], ans, f, l;
bool v[100002];
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    while(f < n && l < n) {
        if(l == n || v[l]) {
            f += 1;
            l = f;
        }
        
    }
    
    cout << ans;
    return 0;
}
