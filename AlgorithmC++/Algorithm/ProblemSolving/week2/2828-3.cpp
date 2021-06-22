//
//  2828-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/03.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, tc, a, f, l, res;
int main(void) {
    cin >> n >> m;
    f = 1; l = m;
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        cin >> a;
        if(a < f) {
            res += abs(a - f);
            f = a; l = f + m - 1;
        } else if(l < a) {
            res += abs(a - l);
            l = a; f = l - m + 1;
        }
    }
    cout << res;
    return 0;
}
