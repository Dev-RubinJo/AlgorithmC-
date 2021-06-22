//
//  1202-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> b;
vector<pii> v;
priority_queue<int> pq;
long long n, k, ans, bidx;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a, c; cin >> a >> c;
        v.push_back({a, c});
    }
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        b.push_back(a);
    }
    sort(v.begin(), v.end());
    sort(b.begin(), b.end());
    
    for(int i = 0; i < k; i++) {
        while(bidx < n && b[i] >= v[bidx].first) {
            pq.push(v[bidx].second);
            bidx += 1;
        }
        if(!pq.empty()) {
            ans += pq.top(); pq.pop();
        }
    }
    cout << ans;
    return 0;
}
