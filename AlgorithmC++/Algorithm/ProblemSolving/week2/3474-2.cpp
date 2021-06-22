//
//  3474-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int tc, n, t, f;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> tc;
    for(int tt = 0; tt < tc; tt++) {
        cin >> n;
        for(int i = 2; i <= n; i *= 2) t += n / i;
        for(int i = 5; i <= n; i *= 5) f += n / i;
        cout << min(t, f) << '\n';
        t = 0; f = 0;
    }
    return 0;
}
