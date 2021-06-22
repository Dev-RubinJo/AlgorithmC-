//
//  1062-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, k, a[26], ans;
vector<string> v;
string s;
void input() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    a['a' - 'a'] = 1;
    a['n' - 'a'] = 1;
    a['t' - 'a'] = 1;
    a['i' - 'a'] = 1;
    a['c' - 'a'] = 1;
}
void func(int idx, int cnt) {
    if(idx == 26 || cnt == k) {
        int res = 0;
        for(int i = 0; i < v.size(); i++) {
            int flag = 0;
            for(int j = 0; j < v[i].size(); j++) {
                if(!a[v[i][j] - 'a']) {
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            res += 1;
        }
        ans = max(ans, res);
        return;
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
    input();
    if(k < 5) cout << 0;
    else if(k == 26) cout << n;
    else {
        k -= 5;
        func(0, 0);
        cout << ans;
    }
    return 0;
}
