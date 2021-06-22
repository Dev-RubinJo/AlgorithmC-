//
//  17471-5.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/21.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, a[11], ans = INT_MAX;
bool visited[11], cmp[11];
vector<int> graph[11];
void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        int p; cin >> p;
        for(int j = 0; j < p; j++) {
            int t; cin >> t;
            graph[i].push_back(t);
        }
    }
}
pii func(int idx, int v) {
    visited[idx] = 1;
    pii res = {1, a[idx]};
    for(int x: graph[idx]) {
        if(visited[x]) continue;
        if(cmp[x] != v) continue;
        pii temp = func(x, v);
        res.first += temp.first;
        res.second += temp.second;
    }
//    cout << res.first << " " << res.second << endl;
    return res;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
//    cout << endl;
    for(int i = 1; i < (1 << n) - 1; i++) {
        fill(visited, visited + 11, 0);
        fill(cmp, cmp + 11, 0);
        int idx1 = 0, idx2 = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) { cmp[j + 1] = 1; idx1 = j + 1; }
            else idx2 = j + 1;
        }
        pii cmp1 = func(idx1, 1);
        pii cmp2 = func(idx2, 0);
        if(cmp1.first + cmp2.first == n) ans = min(ans, abs(cmp1.second - cmp2.second));
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}
