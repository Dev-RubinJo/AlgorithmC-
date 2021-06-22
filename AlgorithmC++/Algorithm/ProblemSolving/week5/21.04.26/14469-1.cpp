//
//  14469-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, ans;
vector<pii> v;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for(auto a: v) {
        if(ans < a.first) {
            ans = a.first + a.second;
        } else {
            ans += a.second;
        }
    }
    cout << ans;
    return 0;
}
