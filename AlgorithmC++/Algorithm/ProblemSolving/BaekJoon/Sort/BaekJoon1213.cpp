//
//  BaekJoon1213.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/23.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<char, int> a, pair<char, int> b) {
    return a.first < b.first;
}

int main(void) {
    string name;
    map<char, int> names;
    vector<pair<char, int> > last;
    int oddCount = 0;
    
    cin >> name;
    for(int i = 0; i < name.size(); i++) {
        names[name[i]] += 1;
    }
    
    for(auto n: names) {
        if(n.second % 2 != 0) oddCount += 1;
    }
    
    if(oddCount > 0 && oddCount != 1) {
        cout << "I'm Sorry Hansoo" << "\n";
        return 0;
    }
    
    
    for(auto n: names) {
        int nSize = n.second;
        for(int i = 0; i < nSize / 2; i++) {
            cout <<  n.first;
            n.second -= 1;
        }
        last.push_back(make_pair(n.first, n.second));
    }
    for(auto n: names) {
        if(n.second % 2 == 1) {
            for(int i = 0; i < last.size(); i++) {
                if(last[i].first == n.first) {
                    last[i].second -= 1;
                    break;
                }
            }
            cout << n.first;
            break;
        }
    }
    for(int i = last.size() - 1; i >= 0; i--) {
        int nSize = last[i].second;
        for(int j = 0; j < nSize; j++) {
            cout << last[i].first;
        }
    }
    
    return 0;
}
