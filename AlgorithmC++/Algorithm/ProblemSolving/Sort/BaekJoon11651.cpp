//
//  BaekJoon11651.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/22.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    vector<pair<int, int> > a;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a.push_back(make_pair(t1, t2));
    }

    sort(a.begin(), a.end(), compare);

    for(int i = 0; i < n; i++) {
        cout << a[i].first << " " << a[i].second << "\n";
    }
    
    return 0;
}
