//
//  17071-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/13.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
const int maxN = 500000;
const int dx[3] = {-1, 1, 0};
const int dm[3] = {1, 1, 2};
int visited[2][500001], n, k, ok;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if(n == k) {
        cout << 0 << endl;
        return 0;
    }
    queue<int> q;
    visited[0][n] = 1;
    int turn = 1;
    q.push(n);
    while(!q.empty()) {
        k += turn;
        if(k > maxN) break;
        if(visited[turn % 2][k]) { ok = 1; break; }
        int thisTurnSize = q.size();
        for(int j = 0; j < thisTurnSize; j++) {
            int dist = q.front(); q.pop();
            for(int i = 0; i < 3; i++) {
                int nx = (dist + dx[i]) * dm[i];
                if(nx < 0 || nx > maxN) continue;
                if(nx == k) {ok = 1; break; }
                if(visited[turn % 2][nx]) continue;
                visited[turn % 2][nx] = 1;
                q.push(nx);
            }
            if(ok) break;
        }
        if(ok) break;
        turn += 1;
    }
    if(ok) cout << turn << endl;
    else cout << -1 << endl;
    return 0;
}
