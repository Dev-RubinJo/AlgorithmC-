//
//  큰 수의 법칙.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/09.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, m, k, count = 0;
    long long ans = 0;
    vector<int> list;
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        list.push_back(temp);
    }
    sort(list.begin(), list.end());
    
    for(int i = 0; i < m; i++) {
        if (count == k) {
            count = 0;
            ans += list[list.size() - 2];
            continue;
        }
        ans += list[list.size() - 1];
        count += 1;
    }
    
    cout << ans;
    
    
    return 0;
}
