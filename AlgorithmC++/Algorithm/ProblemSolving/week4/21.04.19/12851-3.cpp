//
//  12851-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/19.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, k, visited[100001];
int ans = 987654321, cnt;
queue<pair<int, int>> q;
void bfs() {
    while(!q.empty()) {
        int cur, t;
        tie(cur, t) = q.front(); q.pop();
        if(cur == k) {
            if(t < ans) {
                ans = t;
                cnt = 1;
            } else if(t == ans) {
                cnt += 1;
            }
        }

        if(cur + 1 < 100001 && visited[cur + 1] >= t + 1) {
            q.push(pii(cur + 1, t + 1));
            visited[cur + 1] = t + 1;
        }
        if(cur - 1 >= 0 && visited[cur - 1] >= t + 1) {
            q.push(pii(cur - 1, t + 1));
            visited[cur - 1] = t + 1;
        }
        if(cur * 2 < 100001 && visited[cur * 2] >= t + 1) {
            q.push(pii(cur * 2, t + 1));
            visited[cur * 2] = t + 1;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    q.push(pii(n, 0));
    fill(&visited[0], &visited[0] + 30, 987654321);
    visited[n] = 1;
    bfs();
    cout << ans << endl << cnt;
    return 0;
}
