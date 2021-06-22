//
//  12851-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/18.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, k, visited[100001], t = INT_MAX, cnt;
queue<int> q;
void bfs(int x) {
    q.push(x);
    while(!q.empty()) {
        int c = q.front(); q.pop();
        if(c == k) {
            if (t > visited[c]) {
                t = min(t, visited[c]);
                cnt = 1;
            } else if(t == visited[c]) {
                cnt += 1;
            }
        }
        if(c + 1 < 100001 && (c == k || visited[c + 1] >= visited[c]) ) {
            visited[c + 1] = visited[c] + 1;
            q.push(c + 1);
        }
        if(c - 1 >= 0 && (c == k || visited[c - 1] >= visited[c])) {
            visited[c - 1] = visited[c] + 1;
            q.push(c - 1);
        }
        if(c * 2 < 100001 && (c == k || visited[c * 2] >= visited[c])) {
            visited[c * 2] = visited[c] + 1;
            q.push(c * 2);
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fill(visited, visited + 100001, INT_MAX);
    cin >> n >> k;
    visited[n] = 0;
    bfs(n);
    cout << t << endl << cnt;
    return 0;
}
