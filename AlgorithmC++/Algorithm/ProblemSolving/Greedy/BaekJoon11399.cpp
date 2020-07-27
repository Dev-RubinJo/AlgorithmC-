//
//  BaekJoon11399.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/27.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, ans = 0;
    vector<pair<int, int> > a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(make_pair(i + 1, temp));
    }
        
    sort(a.begin(), a.end(), compare);
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            ans += a[j].second;
        
    
    cout << ans;
    return 0;
}
