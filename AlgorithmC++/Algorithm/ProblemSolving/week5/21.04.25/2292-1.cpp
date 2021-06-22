//
//  2292-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/24.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
ll n, cnt = 1, range = 1;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    while(1) {
        if(range >= n)
            break;
        range += 6 * cnt;
        cnt += 1;
    }
    cout << cnt;
    return 0;
}
