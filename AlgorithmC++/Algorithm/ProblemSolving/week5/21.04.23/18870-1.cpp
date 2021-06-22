//
//  18870-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/23.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, pre, temp;
vector<pair<int, int>> v;
vector<int> ans(1000001);
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back({temp, i});
    }
    sort(v.begin(), v.end());
    pre = v[0].first;
    int cnt = 0;
    ans[v[0].second] = 0;
    for(int i = 1; i < n; i++) {
        if(pre == v[i].first)
            ans[v[i].second] = cnt;
        else {
            ans[v[i].second] = cnt + 1;
            pre = v[i].first;
            cnt += 1;
        }
    }
    for(int i = 0; i < n; i++)
    cout << ans[i] << " ";
    return 0;
}
