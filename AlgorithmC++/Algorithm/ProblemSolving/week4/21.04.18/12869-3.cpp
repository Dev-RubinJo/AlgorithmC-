//
//  12869-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/18.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, dp[61][61][61], scv[3];
int at[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3}
};
struct SCV {
    int a, b, c;
};
queue<SCV> q;
int func() {
    while(!q.empty()) {
        SCV scv1 = q.front(); q.pop();
        int a = scv1.a;
        int b = scv1.b;
        int c = scv1.c;
        if(dp[0][0][0]) break;
        for(int i = 0; i < 6; i++) {
            int na = max(0, a - at[i][0]);
            int nb = max(0, b - at[i][1]);
            int nc = max(0, c - at[i][2]);
            if(dp[na][nb][nc]) continue;
            dp[na][nb][nc] = dp[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return dp[0][0][0];
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> scv[i];
    q.push({scv[0], scv[1], scv[2]});
    cout << func();
    
    return 0;
}
