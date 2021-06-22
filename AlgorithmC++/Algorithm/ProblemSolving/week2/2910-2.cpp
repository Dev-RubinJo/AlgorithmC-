//
//  2910-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/03.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
map<int, int> m1, m2;
vector<pair<int, int> > v;
int n, c, temp;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second)
        return m2[a.first] < m2[b.first];
    return a.second > b.second;
}
int main(void) {
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        m1[temp] += 1;
        if(!m2[temp]) m2[temp] = i + 1;
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
