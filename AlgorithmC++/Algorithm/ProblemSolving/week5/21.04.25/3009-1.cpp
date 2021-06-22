//
//  3009-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
map<int, int> m1, m2;
int a, b;
int main(void) {
    for(int i = 0; i < 3; i++) {
        cin >> a >> b;
        m1[a] += 1;
        m2[b] += 1;
    }
    for(auto it: m1) {
        if(it.second == 1) cout << it.first << " ";
    }
    for(auto it: m2) {
        if(it.second == 1) cout << it.first << " ";
    }
    return 0;
}
