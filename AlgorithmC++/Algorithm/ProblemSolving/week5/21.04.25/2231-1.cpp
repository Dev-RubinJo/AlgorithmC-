//
//  2231-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, ans = INT_MAX;
int main(void) {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int sum = i, temp = i;
        while(temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if(sum == n) {
            ans = min(ans, i);
        }
    }
    if(ans == INT_MAX) cout << 0;
    else cout << ans;
    return 0;
}
