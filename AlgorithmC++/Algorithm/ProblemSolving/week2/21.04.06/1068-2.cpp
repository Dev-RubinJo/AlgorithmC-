//
//  1068-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
vector<int> v[51];
int n, nd, del, start;
int dfs(int s) {
    if(v[s].empty()) return 1;
    int res = 0;
    for(int i = 0; i < v[s].size(); i++)
        res += dfs(v[s][i]);
    return res;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nd;
        if(nd == -1) {
            start = i;
            continue;
        }
        v[nd].push_back(i);
    }
    cin >> del;
    if(del != start) {
        for(int i = 0; i < n; i++) {
            auto it = find(v[i].begin(), v[i].end(), del);
            if(it != v[i].end()) {
                v[i].erase(it);
                break;
            }
        }
        cout << dfs(start);
    } else cout << 0;
    return 0;
}
