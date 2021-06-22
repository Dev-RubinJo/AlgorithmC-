//
//  1316-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, ans;
vector<string> v;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        v.push_back(s);
    }
    for(int i = 0; i < v.size(); i++) {
        int a[26] = {0, };
        char prev = '0';
        bool flag = 0;
        for(int j = 0; j < v[i].size(); j++) {
            if(v[i][j] != prev) {
                if(a[v[i][j] - 'a']) {
                    flag = 1;
                    break;
                }
            }
            prev = v[i][j];
            a[v[i][j] - 'a'] = 1;
        }
        if(!flag) ans += 1;
    }
    cout << ans;
    return 0;
}
