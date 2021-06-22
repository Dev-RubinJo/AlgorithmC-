//
//  16922-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/21.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int dp[1001], n, ans;
int nums[] = {1, 5, 10, 50};
void func(int idx, int s, int num) {
    if(idx == n) {
        if(!dp[num]) {
            ans += 1;
            dp[num] = 1;
        }
        return;
    }
    for(int i = s; i < 4; i++) {
        num += nums[i];
        func(idx + 1, i, num);
        num -= nums[i];
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    func(0, 0, 0);
    cout << ans << endl;
    return 0;
}
