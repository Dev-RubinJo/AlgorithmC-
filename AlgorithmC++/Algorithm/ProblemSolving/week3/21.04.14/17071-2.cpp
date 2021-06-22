//
//  17071-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/14.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, k, visited[2][500001], ok;
int dx[] = {-1, 1, 0};
int dy[] = {1, 1, 2};
queue<int> q;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if(n == k) {
        cout << 0;
        return 0;
    }
    visited[0][n] = 1;
    int turn = 1;
    q.push(n);
    while(!q.empty()) {
        k += turn;
        if(k > 500000) break;
        if(visited[turn % 2][k]) { ok = 1; break; }
        int nowTurn = q.size();
        for(int j = 0; j < nowTurn; j++) {
            int dist = q.front(); q.pop();
            for(int i = 0; i < 3; i++) {
                int nx = (dist + dx[i]) * dy[i];
                if(nx < 0 || nx > 500000) continue;
                if(nx == k) { ok = 1; break; }
                if(visited[turn % 2][nx]) continue;
                visited[turn % 2][nx] = 1;
                q.push(nx);
            }
            if(ok) break;
        }
        if(ok) break;
        turn += 1;
    }
    if(ok) cout << turn;
    else cout << -1;
    return 0;
}
