//
//  17471-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/14.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, tempN, temp, ans = 987654321, cmp[11], visited[11];
int peo[11];
vector<int> a[11];
pii go(int x, int v) {
    visited[x] = 1;
    pii res = {1, peo[x]};
    for(int i: a[x]) {
        if(cmp[i] != v) continue;
        if(visited[i]) continue;
        pii t = go(i, v);
        res.first += t.first;
        res.second += t.second;
    }
    return res;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> peo[i];
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        for(int j = 0; j < temp; j++) {
            cin >> tempN;
            a[i].push_back(tempN);
            a[tempN].push_back(i);
        }
    }
    for(int i = 1; i < (1 << n) - 1; i++) {
        fill(cmp, cmp + 11, 0);
        fill(visited, visited + 11, 0);
        int idx1 = -1, idx2 = -1;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {cmp[j + 1] = 1; idx1 = j + 1; }
            else idx2 = j + 1;
        }
        pii cmp1 = go(idx1, 1);
        pii cmp2 = go(idx2, 0);
        if(cmp1.first + cmp2.first == n) ans = min(ans, abs(cmp1.second - cmp2.second));
    }
    cout << ans;
    return 0;
}
// MARK: 아직 완벽히 내 문제가 안됐다.
// MARK: 이해가 완벽히 될때까지 계속해서 봐야할 문제.
