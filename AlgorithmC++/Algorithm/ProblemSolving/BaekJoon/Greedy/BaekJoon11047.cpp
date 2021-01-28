//
//  BaekJoon11047.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/27.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k, ans = 0;
    cin >> n >> k;
    int coins[10];
    for(int i = n - 1; i >= 0; i--)
        cin >> coins[i];
    
    for(int i = 0; i < n; i++) {
        ans += k / coins[i];
        k %= coins[i];
        if(k == 0)
            break;
    }
    
    cout << ans;
    
    return 0;
}
