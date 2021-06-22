//
//  3474-l.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/08.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
int tc, n, f;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> n;
        for(int i = 5; i <= n; i *= 5) f += n / i;
        cout << f << endl;
        f = 0;
    }
    return 0;
}
