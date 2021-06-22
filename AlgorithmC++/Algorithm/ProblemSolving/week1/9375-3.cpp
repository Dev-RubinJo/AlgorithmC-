//
//  9375-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
map<string, int> m1;
int tc, n, res = 1;
string temp1, temp2;
int main(void) {
    cin >> tc;
    for(int tt = 0; tt < tc; tt++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> temp1 >> temp2;
            m1[temp2] += 1;
        }
        for(auto it = m1.begin(); it != m1.end(); it++) {
            res *= (it->second + 1);
        }
        cout << res - 1 << '\n';
        res = 1;
        m1.clear();
    }
    return 0;
}
