//
//  1920.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, m;
map<int, int> m1;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        m1[t] = 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        if(m1[t]) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
