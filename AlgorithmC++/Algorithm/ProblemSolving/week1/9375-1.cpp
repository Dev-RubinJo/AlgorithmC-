//
//  9375-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int tc, n, res = 0;
map<string, vector<string> > _map;
string temp1, temp2;
int main(void) {
    cin >> tc;
    for(int qq = 0; qq < tc; qq++) {
        cin >> n;
        res = 1;
        for(int i = 0; i < n; i++) {
            cin >> temp1 >> temp2;
            _map[temp2].push_back(temp1);
        }
        for(map<string, vector<string> >::iterator it = _map.begin(); it != _map.end(); it++) {
            res *= it->second.size() + 1;
        }
        cout << res - 1 << '\n';
        _map.clear();
    }
    return 0;
}
// MARK: 조합에 대해서 더 공부하기
