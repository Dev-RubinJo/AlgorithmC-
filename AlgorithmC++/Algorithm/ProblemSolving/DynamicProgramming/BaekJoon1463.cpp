//
//  BaekJoon1463.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/23.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    for(int i = 2; i < n + 1; i++) {
        dp[i] = dp[i - 1] + 1;
        if(i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if(i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    cout << dp[n];
    
    return 0;
}
