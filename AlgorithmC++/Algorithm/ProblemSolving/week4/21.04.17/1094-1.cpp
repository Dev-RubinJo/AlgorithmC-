//
//  1094-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/17.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, x, i = 6;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> x;
    while(x > 0) {
        if(x >= (1 << i)) {
            x -= (1 << i);
            n += 1;
        }
        i -= 1;
    }
    cout << n;
    return 0;
}
