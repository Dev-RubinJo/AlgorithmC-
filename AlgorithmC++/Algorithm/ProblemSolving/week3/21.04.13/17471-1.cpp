//
//  17471-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/13.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, a[11], visited[11], temp, ans = 987654321, cmp[11];
vector<int> v[11];
pii dfs(int x, int value) {
    visited[x] = 1;
    pii res = {1, a[x]};
    for(int y: v[x]) {
        if(cmp[y] != value) continue;
        if(visited[y]) continue;
        pii t = dfs(y, value);
        res.first += t.first;
        res.second += t.second;
    }
    return res;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        int k;
        for(int j = 0; j < temp; j++) {
            cin >> k;
            v[i].push_back(k);
            v[k].push_back(i);
        }
    }
    for(int i = 1; i < (1 << n) - 1; i++) {
        fill(cmp, cmp + 11, 0);
        fill(visited, visited + 11, 0);
        int idx1 = -1, idx2 = -1;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) { cmp[j + 1] = 1; idx1 = j + 1; }
            else idx2 = j + 1;
        }
        pii cmp1 = dfs(idx1, 1);
        pii cmp2 = dfs(idx2, 0);
        if(cmp1.first + cmp2.first == n) ans = min(ans, abs(cmp1.second - cmp2.second));
    }
    cout << (ans == 987654321 ? -1 : ans);
    return 0;
}
