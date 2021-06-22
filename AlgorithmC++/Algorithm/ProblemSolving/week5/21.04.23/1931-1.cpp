//
//  1931-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/23.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
vector<pair<int, int>> v;
int n, cnt, pre;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    cnt = 1;
    pre = v[0].second;
    for(int i = 1; i < n; i++) {
        if(v[i].first >= pre) {
            cnt += 1;
            pre = v[i].second;
        }
    }
    cout << cnt;
    return 0;
}
