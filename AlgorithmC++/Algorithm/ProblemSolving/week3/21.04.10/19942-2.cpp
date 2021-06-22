//
//  19942-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/10.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, mp, mf, ms, mv, mc = 987654321;
int p, f, s, v, c;
int a[16][5];
map<int, vector<vector<int>>> m;
void solution() {
    for(int i = 1; i < (1 << n); i++) {
        vector<int> ve;
        p = f = s = v = c = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                ve.push_back(j + 1);
                p += a[j][0]; f += a[j][1]; s += a[j][2]; v += a[j][3]; c += a[j][4];
            }
        }
        if(p >= mp && f >= mf && s >= ms && v >= mv) {
            if(mc >= c) {
                mc = c;
                m[c].push_back(ve);
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
    solution();
    sort(m[mc].begin(), m[mc].end());
    if(mc == 987654321) cout << -1;
    else {
        cout << mc << endl;
        for(auto a: m[mc][0])
            cout << a << " ";
    }
    
    return 0;
}
