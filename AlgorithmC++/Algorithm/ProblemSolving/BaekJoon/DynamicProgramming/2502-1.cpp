//
//  2502-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/21.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int dp[31];
int d, k, a, b;
int main() {
    
    cin >> d >> k;
    dp[1] = dp[2] = 1;
    for(int i = 3; i <= d; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    for(int i = 1;; i++) {
        a = i;
        if ((k - dp[d - 2] * a) % dp[d - 1])
            continue;
        b = (k - dp[d - 2] * a) / dp[d - 1];
        break;
    }
    cout << a << '\n' << b << '\n';
    
    return 0;
}
