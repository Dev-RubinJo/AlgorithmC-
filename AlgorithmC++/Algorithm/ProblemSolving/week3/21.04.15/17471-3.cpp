//
//  17471-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/15.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, a[11], visited[11], res = INT_MAX, cmp[11];
vector<int> p[11];
pii func(int x, int value) {
    visited[x] = 1;
    pii ans = {1, a[x]};
    for(int y: p[x]) {
        if(cmp[y] != value) continue;
        if(visited[y]) continue;
        pii temp = func(y, value);
        ans.first += temp.first;
        ans.second += temp.second;
    }
    return ans;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        int to; cin >> to;
        for(int i = 0; i < to; i++) {
            int num; cin >> num;
            p[i].push_back(num);
            p[num].push_back(i);
        }
    }
    for(int i = 1; i < (1 << n); i++) {
        fill(cmp, cmp + 11, 0);
        fill(visited, visited + 11, 0);
        int idx1 = -1, idx2 = -1;
        for(int j = 0; j < n; j++) {
            if(i & j) { cmp[j + 1] = 1; idx1 = j + 1; }
            else idx2 = j + 1;
        }
        pii cmp1 = func(idx1, 1);
        pii cmp2 = func(idx2, 0);
        if(cmp1.first + cmp2.first == n) res = min(res, abs(cmp1.second - cmp2.second));
    }
    if(res == INT_MAX) cout << -1;
    else cout << res;
    return 0;
}
