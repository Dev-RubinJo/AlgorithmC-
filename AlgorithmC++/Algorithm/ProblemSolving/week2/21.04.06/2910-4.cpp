//
//  2910-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
map<int, int> m1, m2;
int n, c;
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return m2[a.first] < m2[b.first];
    return a.second > b.second;
}
int main(void) {
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> c;
        m1[c] += 1;
        if(!m2[c]) m2[c] = i + 1;
    }
    for(auto it: m1)
        v.push_back(make_pair(it.first, it.second));
    sort(v.begin(), v.end(), cmp);
    for(auto a: v)
        for(int i = 0; i < a.second; i++) cout << a.first << " ";
    return 0;
}
