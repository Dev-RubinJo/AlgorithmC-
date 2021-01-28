//
//  BaekJoon11652.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/22.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, maxValue = 0;
    long long key;
    map<long long, int> a;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        long long s;
        cin >> s;
        a[s] += 1; // map에서 int형 인경우 초기값은 0이다.
        
    }
    for(map<long long, int>::iterator it = a.begin(); it != a.end(); it++) {
        if(it->second > maxValue) {
            maxValue = it->second;
            key = it->first;
        } else if(it->second == maxValue) {
            if(key > it->first) key = it->first;
        }
    }
    
    cout << key;
    
    return 0;
}

