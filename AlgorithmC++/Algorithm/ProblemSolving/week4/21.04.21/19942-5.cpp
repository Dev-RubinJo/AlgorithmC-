//
//  19942-5.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/21.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, mp, mf, ms, mv, mc = INT_MAX, a[16][5], p, f, s, v, c;
map<int, vector<vector<int>>> m;
void func() {
    for(int i = 1; i < (1 << n); i++) {
        p = f = s = v = c = 0;
        vector<int> ve;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                ve.push_back(j + 1);
                p += a[j][0]; f += a[j][1]; s += a[j][2]; v += a[j][3]; c += a[j][4];
            }
        }
        if(p >= mp && f >= mf && s >= ms && v >= mv) {
            if(mc >= c) {
                mc = c;
                m[mc].push_back(ve);
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
    func();
    if(mc == INT_MAX) cout << -1;
    else {
        sort(m[mc].begin(), m[mc].end());
        cout << mc << endl;
        for(int ve: m[mc][0]) cout << ve << " ";
    }
    return 0;
}
