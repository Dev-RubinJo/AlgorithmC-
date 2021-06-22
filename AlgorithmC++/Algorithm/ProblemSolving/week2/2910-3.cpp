//
//  2910-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, c, t;
map<int, int> m1, m2;
vector<pair<int, int> > v;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second)
        return m2[a.first] < m2[b.first];
    return a.second > b.second;
}
int main(void) {
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> t;
        m1[t] += 1;
        if(!m2[t]) m2[t] = i + 1;
    }
    for(auto it: m1)
        v.push_back(make_pair(it.first, it.second));
    sort(v.begin(), v.end(), cmp);
    for(auto ve: v) {
        for(int i = 0; i < ve.second; i++) {
            cout << ve.first << " "; 
        }
    }
    return 0;
}
