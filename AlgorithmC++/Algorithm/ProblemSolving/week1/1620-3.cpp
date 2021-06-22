//
//  1620-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
map<string, int> map1;
map<int, string> map2;
int n, m;
string s;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        map1[s] = i + 1;
        map2[i + 1] = s;
    }
    for(int i = 0; i < m; i++) {
        cin >> s;
        if(s[0] >= 'A' && s[0] <= 'Z') cout << map1[s] << '\n';
        else cout << map2[stoi(s)] << '\n';
    }
    return 0;
}
