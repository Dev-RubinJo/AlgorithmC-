//
//  BaekJoon15702.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/31.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main(void) {
    int n, m;
    
    vector<pair<int, int> > list;
    cin >> n >> m;
    vector<int> scores(n);
    
    for(int i = 0; i < n; i++)
        cin >> scores[i];
    
    for(int i = 0; i < m; i++) {
        int no, score = 0;
        cin >> no;
        for(int j = 0; j < n; j++) {
            string c;
            cin >> c;
            if(c == "O") score += scores[j];
        }
        list.push_back(make_pair(no, score));
    }
    
    sort(list.begin(), list.end(), compare);
    
    cout << list[0].first << " " << list[0].second;
    
    return 0;
}
