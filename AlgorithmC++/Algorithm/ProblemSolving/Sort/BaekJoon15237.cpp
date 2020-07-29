//
//  BaekJoon15237.cpp
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

bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
    if(a.second.first == b.second.first) return a.second.second < b.second.second;
    return a.second.first > b.second.first;
    
}

int main(void) {
    int n, c;
    vector<pair<int, pair<int, int> > > list;
    cin >> n >> c;
    
    for(int i = 0; i < n; i++) {
        int temp, noThere = 0;
        cin >> temp;
        
        for(int j = 0; j < list.size(); j++) {
            if(list[j].first == temp) {
                list[j].second.first += 1;
                noThere = 1;
                break;
            }
        }
        if(!noThere || list.size() == 0) {
            list.push_back(make_pair(temp, make_pair(1, list.size())));
        }
    }
    
    sort(list.begin(), list.end(), compare);
    
    for(int i = 0; i < list.size(); i++) {
        for(int j = 0; j < list[i].second.first; j++) {
            cout << list[i].first << " ";
        }
        
    }
    
    return 0;
}
