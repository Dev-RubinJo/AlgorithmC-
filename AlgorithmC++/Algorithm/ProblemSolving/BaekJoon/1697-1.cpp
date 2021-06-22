//
//  1697-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/11.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, k, visited[100001];
int ans;
queue<pair<int, int>> q;
void bfs() {
    while(!q.empty()) {
        int cur, t;
        tie(cur, t) = q.front(); q.pop();
        if(cur == k) {
            ans = t;
            return;
        }
        if(cur + 1 < 100001 && !visited[cur + 1]) {
            q.push(pii(cur + 1, t + 1));
            visited[cur + 1] = 1;
        }
        if(cur - 1 >= 0 && !visited[cur - 1]) {
            q.push(pii(cur - 1, t + 1));
            visited[cur - 1] = 1;
        }
        if(cur * 2 < 100001 && !visited[cur * 2]) {
            q.push(pii(cur * 2, t + 1));
            visited[cur * 2] = 1;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    q.push(pii(n, 0));
    visited[n] = 1;
    bfs();
    cout << ans;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, k, visited[30], cnt;
void dfs(int x) {
    if(x == k) {
        return;
    }
    for(int i = 0; i < 3; i++) {
        int nx = 0;
        if(i == 0) nx = x - 1;
        else if(i == 1) nx = x + 1;
        else if(i == 2) nx = x * 2;
        cnt += 1;
        if(nx <= 0 || nx >= 100000 || visited[nx] < cnt) continue;
        visited[nx] = cnt;
        dfs(nx);
        cnt -= 1;
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    fill(&visited[0], &visited[0] + 30, 987654321);
    visited[n] = 0;
    dfs(n);
    cout << visited[k];
    return 0;
}
*/
