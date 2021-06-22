//
//  12869-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/13.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n;
int scv[3], dp[61][61][61], visited[61][61][61];
int nums[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3}
};
struct A {
    int a, b, c;
};
queue<A> q;
int solve(int a, int b, int c) {
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while(!q.empty()) {
        int a1 = q.front().a;
        int b1 = q.front().b;
        int c1 = q.front().c;
        q.pop();
        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++) {
            int na = max(0, a1 - nums[i][0]);
            int nb = max(0, b1 - nums[i][1]);
            int nc = max(0, c1 - nums[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a1][b1][c1] + 1;
            q.push({na, nb, nc});
        }
    }
    return visited[0][0][0] - 1;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> scv[i];
    cout << solve(scv[0], scv[1], scv[2]);
    return 0;
}
