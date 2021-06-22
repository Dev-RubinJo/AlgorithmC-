//
//  mcc3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/15.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -2;
    vector<int> v[a.size()];
    for(int i = 0; i < edges.size(); i++) {
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    
    
    return answer;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution({-5, 0, 2, 1, 2}, {{0, 1}, {3, 4}, {2, 3}, {0, 3}});
    return 0;
}
