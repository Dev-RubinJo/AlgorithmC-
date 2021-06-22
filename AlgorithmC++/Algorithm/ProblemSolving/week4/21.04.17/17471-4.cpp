//
//  17471-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/17.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, a[11], ans = INT_MAX, cmp[11], visited[11];
vector<int> v[11];

pii func(int x, int clan) {
    visited[x] = 1;
    pii res = {1, a[x]};
    for(int temp: v[x]) {
        if(visited[temp]) continue;
        if(cmp[temp] != clan) continue;
        pii be = func(temp, clan);
        res.first += be.first;
        res.second += be.second;
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        for(int j = 0; j < temp; j++) {
            int t; cin >> t;
            v[i].push_back(t);
            v[t].push_back(i);
        }
    }
    for(int i = 1; i < (1 << n) - 1; i++) {
        int idx1 = -1, idx2 = -1;
        fill(visited, visited + 11, 0);
        fill(cmp, cmp + 11, 0);
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) { idx1 =  j + 1; cmp[j + 1] = 1; }
            else idx2 = j + 1;
        }
        pii cmp1 = func(idx1, 1);
        pii cmp2 = func(idx2, 0);
        if(cmp1.first + cmp2.first == n) ans = min(ans, abs(cmp1.second - cmp2.second));
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    cout << (1 << n);
    return 0;
}
