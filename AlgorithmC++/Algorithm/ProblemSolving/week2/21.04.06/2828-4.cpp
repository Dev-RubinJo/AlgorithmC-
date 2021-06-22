//
//  2828-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, f, l, ac, a;
int main(void) {
    cin >> n >> m;
    cin >> ac;
    n = 0;
    f = 1; l = m;
    for(int i = 0; i < ac; i++) {
        cin >> a;
        if(a < f) {
            n += f - a;
            f = a; l = f + m - 1;
        } else if (a > l) {
            n += a - l;
            l = a; f = l - m + 1;
        }
    }
    cout << n;
    return 0;
}
