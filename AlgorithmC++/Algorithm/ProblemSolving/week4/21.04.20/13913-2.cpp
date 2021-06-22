//
//  13913-2.cpp
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
int n, k, ans, visited[100001], route[100001];
queue<pii> q;
void input() {
    cin >> n >> k;
    fill(visited, visited + 100001, INT_MAX);
}
void bfs() {
    visited[n] = 0;
    route[n] = 0;
    q.push(pii(n, 0));
    while(!q.empty()) {
        int c, t;
        tie(c, t) = q.front(); q.pop();
        if(c == k) {
            ans = t;
            break;
        }
        if(c + 1 <= 100000 && visited[c + 1] >= t + 1) {
            visited[c + 1] = t + 1;
            route[c + 1] = c;
            q.push(pii(c + 1, t + 1));
        }
        if(c - 1 >= 0 && visited[c - 1] >= t + 1) {
            visited[c - 1] = t + 1;
            route[c - 1] = c;
            q.push(pii(c - 1, t + 1));
        }
        if(c * 2 <= 100000 && visited[c * 2] >= t + 1) {
            visited[c * 2] = t + 1;
            route[c * 2] = c;
            q.push(pii(c * 2, t + 1));
        }
    }
}
void print() {
    cout << ans << endl;
    int a = k;
    vector<int> v;
    while(a != n) {
        v.push_back(a);
        a = route[a];
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    for(int i: v) cout << i << " ";
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    bfs();
    print();
    return 0;
}
