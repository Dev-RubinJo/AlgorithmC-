//
//  19942-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/15.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, a[16][6];
int mp, mf, ms, mv, mc = INT_MAX, p, f, s, v, c;
map<int, vector<vector<int>>> m1;
void solution() {
    for(int i = 1; i <= (1 << n); i++) {
        p = f = s = v = c = 0;
        vector<int> ve;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                p += a[j][0]; f += a[j][1]; s += a[j][2]; v += a[j][3]; c += a[j][4];
                ve.push_back(j + 1);
            }
        }
        if(p >= mp && f >= mf && s >= ms && v >= mv) {
            if(mc >= c) {
                mc = c;
                m1[mc].push_back(ve);
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
    solution();
    if(mc == INT_MAX) cout << -1;
    else {
        sort(m1[mc].begin(), m1[mc].end());
        cout << mc << endl;
        for(int a: m1[mc][0]) cout << a << " ";
    }
    return 0;
}
