//
//  1781-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans;
vector<pair<ll, ll>> v;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if(pq.size() > v[i].first) {
            pq.pop();
        }
    }
    
    while(!pq.empty()) {
        ans += pq.top(); pq.pop();
    }
    cout << ans;
    return 0;
}
