//
//  19942-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/15.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, ing[16][6], mp, mf, ms, mv, mc = INT_MAX;
map<int, vector<vector<int>>> m1;
void solution() {
    for(int i = 1; i < (1 << n); i++) {
        int p = 0, f = 0, s = 0, v = 0, c = 0;
        vector<int> orders;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                p += ing[j][0]; f += ing[j][1]; s += ing[j][2]; v += ing[j][3]; c += ing[j][4];
                orders.push_back(j + 1);
            }
        }
        if(p >= mp && f >= mf && s >= ms && v >= mv) {
            if(mc >= c) {
                m1[c].push_back(orders);
                mc = c;
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++)
        cin >> ing[i][0] >> ing[i][1] >> ing[i][2] >> ing[i][3] >> ing[i][4];
    solution();
    if(mc == INT_MAX) cout << -1;
    else {
        sort(m1[mc].begin(), m1[mc].end());
        cout << mc << endl;
        for(int a: m1[mc][0]) cout << a << " ";
    }
    return 0;
}
