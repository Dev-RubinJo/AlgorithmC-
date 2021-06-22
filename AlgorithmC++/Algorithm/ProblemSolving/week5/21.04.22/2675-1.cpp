//
//  2675-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int tc, n;
string s;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> n >> s;
        string res;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < n; j++) {
                res += string(1, s[i]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
