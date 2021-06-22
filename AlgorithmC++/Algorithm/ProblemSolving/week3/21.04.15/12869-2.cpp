//
//  12869-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/15.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int dp[61][61][61], n, x, y, z;
int at[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3}
};
struct scv {
    int a, b, c;
};
queue<scv> q;
int sol(int a1, int b1, int c1) {
    q.push({a1, b1, c1});
    dp[a1][b1][c1] = 1;
    while(!q.empty()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(dp[0][0][0]) break;
        for(int i = 0; i < 6; i++) {
            int na = max(0, a - at[i][0]);
            int nb = max(0, b - at[i][1]) ;
            int nc = max(0, c - at[i][2]);
            dp[na][nb][nc] = dp[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return dp[0][0][0] - 1;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> x >> y >> z;
    cout << sol(x, y, z);
    return 0;
}
