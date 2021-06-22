//
//  1325-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, visited[100001], a, b, maxC, cnt[100001];
vector<int> v[100001];
int dfs(int i) {
    visited[i] = 1;
    int res = 1;
    for(int j = 0; j < v[i].size(); j++) {
        if(visited[v[i][j]]) continue;
        res += dfs(v[i][j]);
    }
    if(res != 1) return res;
    return 1;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int t = 0; t < m; t++) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i = 1; i < n + 1; i++) {
        fill(&visited[0], &visited[0] + 100001, 0);
        cnt[i] = dfs(i);
        maxC = max(cnt[i], maxC);
    }
    for(int i = 1; i < n + 1; i++)
        if(maxC == cnt[i]) cout << i << " ";
    
    return 0;
}
