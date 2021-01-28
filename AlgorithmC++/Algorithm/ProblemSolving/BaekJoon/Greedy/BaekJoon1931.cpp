//
//  BaekJoon1931.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/10.
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

int main(void) {
    int n, ans = 1;
    pair<int, int> base;
    vector<pair<int, int> > lists;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lists.push_back(make_pair(a, b));
    }

    sort(lists.begin(), lists.end(), compare);
    
    base = lists[0];
    for(int i = 1; i < lists.size(); i++) {
        if(base.second <= lists[i].first) {
            ans += 1;
            base = lists[i];
        }
    }
    cout << ans;
    return 0;
}
