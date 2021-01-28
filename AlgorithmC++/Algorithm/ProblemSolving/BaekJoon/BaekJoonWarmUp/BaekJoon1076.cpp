//
//  BaekJoon1076.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/07.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
    map<string, pair<int, int> > juhang;
    vector<string> colors(3);
    long long ans = 0;
    
    for(int i = 0; i < 3; i++) {
        cin >> colors[i];
    }
    
    
    juhang.insert(make_pair("black", make_pair(0, 1)));
    juhang.insert(make_pair("brown", make_pair(1, 10)));
    juhang.insert(make_pair("red", make_pair(2, 100)));
    juhang.insert(make_pair("orange", make_pair(3, 1000)));
    juhang.insert(make_pair("yellow", make_pair(4, 10000)));
    juhang.insert(make_pair("green", make_pair(5, 100000)));
    juhang.insert(make_pair("blue", make_pair(6, 1000000)));
    juhang.insert(make_pair("violet", make_pair(7, 10000000)));
    juhang.insert(make_pair("grey", make_pair(8, 100000000)));
    juhang.insert(make_pair("white", make_pair(9, 1000000000)));
    
    for(int i = 0; i < 3; i++) {
        if(i == 2) {
            ans *= juhang[colors[i]].second;
            break;
        }
        ans = ans * 10 + juhang[colors[i]].first;
    }
    
    cout << ans;
    
    return 0;
}
