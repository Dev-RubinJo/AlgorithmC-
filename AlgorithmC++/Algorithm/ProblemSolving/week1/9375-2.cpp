//
//  9375-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/29.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int tc, n, res = 1;
map<string, int> _map;
string temp1, temp2;
int main(void) {
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> temp1 >> temp2;
            _map[temp2] += 1;
        }
        for(map<string, int>::iterator it = _map.begin(); it != _map.end(); it++) {
            res *= it->second + 1;
        }
        cout << res - 1 << '\n';
        res = 1; _map.clear();
    }
    return 0;
}
