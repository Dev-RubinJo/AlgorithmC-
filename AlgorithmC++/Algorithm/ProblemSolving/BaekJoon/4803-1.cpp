//
//  4803-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/08.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
int n, m, a, b, visited[501];
bool isCycle;
vector<int> v[501];
vector<int> ro;
void dfs(int num) {
    if(visited[num] && v[num].empty()) isCycle = 1;
    visited[num] = 1;
    for(int i = 0; i < v[num].size(); i++) {
        if(!visited[v[num][i]]) dfs(v[num][i]);
        else {
            isCycle = 1;
            return;
        }
    }
}
int main(void) {
    int casei = 0;
    while(1) {
        casei += 1;
        int t = 0;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i = 0; i < 502; i++) v[i].clear();
        ro.clear();
        fill(&visited[0], &visited[0] + 501, 0);
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            ro.push_back(a);
        }
        for(int i = 0; i < n; i++) {
            isCycle = 0;
            if(i < ro.size()){
                dfs(ro[i]);
            }
            if(isCycle) continue;
            t += 1;
        }
        if(t == 0) cout << "Case " + to_string(casei) + ": No Trees.\n";
        else if(t == 1) cout << "Case " + to_string(casei) + " There is one tree.\n";
        else if(t > 1) cout << "Case " + to_string(casei) + ": A forest of " + to_string(t) +" trees.\n";
    }
    return 0;
}
