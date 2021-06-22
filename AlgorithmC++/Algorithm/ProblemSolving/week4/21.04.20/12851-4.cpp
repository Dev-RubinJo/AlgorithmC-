//
//  12851-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/20.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, k, visited[100001], cnt;
queue<pii> q;
void input() {
    cin >> n >> k;
    fill(visited, visited + 100001, INT_MAX);
}
void bfs() {
    visited[n] = 0;
    q.push(pii(n, 0));
    while(!q.empty()) {
        int c, t;
        tie(c, t) = q.front(); q.pop();
        if(c == k) cnt += 1;
        if(c + 1 <= 100000 && visited[c + 1] >= t + 1) {
            q.push(pii(c + 1, t + 1));
            visited[c + 1] = t + 1;
        }
        if(c - 1 >= 0 && visited[c - 1] >= t + 1) {
            q.push(pii(c - 1, t + 1));
            visited[c - 1] = t + 1;
        }
        if(c * 2 <= 100000 && visited[c * 2] >= t + 1) {
            q.push(pii(c * 2, t + 1));
            visited[c * 2] = t + 1;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    bfs();
    cout << visited[k] << endl << cnt;
    return 0;
}
