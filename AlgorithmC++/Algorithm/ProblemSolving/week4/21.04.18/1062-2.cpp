//
//  1062-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/18.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, k, ans;
bool a[26];
vector<string> v;
string s;
void func(int idx, int cnt) {
    if(cnt == k) {
        int res = 0;
        for(int i = 0; i < v.size(); i++) {
            int flag = 0;
            for(int j = 0; j < v[i].size(); j++) {
                if(a[v[i][j] - 'a']) continue;
                else flag = 1;
            }
            if(flag) continue;
            res += 1;
        }
        ans = max(res, ans);
    }
    for(int i = idx; i < 26; i++) {
        if(a[i]) continue;
        a[i] = 1;
        func(i, cnt + 1);
        a[i] = 0;
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if(k < 5) {
        cout << 0;
    } else if (k == 26) {
        cout << n;
    } else {
        a['a' - 'a'] = 1;
        a['n' - 'a'] = 1;
        a['t' - 'a'] = 1;
        a['i' - 'a'] = 1;
        a['c' - 'a'] = 1;
        for(int j = 0; j < n; j++) {
            cin >> s;
            v.push_back(s);
        }
        k -= 5;
        func(0, 0);
        cout << ans;
    }
    return 0;
}
