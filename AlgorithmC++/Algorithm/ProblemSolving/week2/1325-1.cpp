//
//  1325-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
vector<int> v[10001];
int n, m, a, b, cnt, maxC, visited[10001];
int arr[10001];
void dfs(int x) {
    cnt += 1;
    visited[x] = 1;
    if(v[x].empty()) return;
    for(int i = 0; i < v[x].size(); i++){
        if(!visited[v[x][i]]) dfs(v[x][i]); // MARK: dfs에서 visited로 예외처리하는 상황을 다시 한번 느끼게 해준 문제
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        cnt = 0;
        fill(&visited[0], &visited[0] + 10001, 0);
        dfs(i);
        arr[i] = cnt;
        maxC = max(cnt, maxC);
    }
    for(int i = 1; i <= n; i++)
        if(arr[i] == maxC) cout << i << " ";
    return 0;
}
