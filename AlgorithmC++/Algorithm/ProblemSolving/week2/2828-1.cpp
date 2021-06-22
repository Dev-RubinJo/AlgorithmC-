//
//  2828-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/01.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int f, l, n, m, j, res;
int a;
int main(void) {
    cin >> n >> m;
    f = 1; l = (m > 1) ? m : 1;
    cin >> j;
    for(int i = 0; i < j; i++) {
        cin >> a;
        if(a < f) {
            res += abs(f - a);
            f = a; l = f + m - 1;
        } else if(a > l) {
            res += abs(l - a);
            l = a; f = l - m + 1;
        }
    }
    cout << res;
    return 0;
}
