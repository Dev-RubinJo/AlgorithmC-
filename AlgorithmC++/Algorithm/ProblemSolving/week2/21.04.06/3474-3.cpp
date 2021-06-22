//
//  3474-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int tc, n, f;
int main(void) {
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> n;
        for(int i = 5;  i <= n; i *= 5) f += n / i;
        cout << f << '\n';
        f = 0;
    }
    return 0;    
}
