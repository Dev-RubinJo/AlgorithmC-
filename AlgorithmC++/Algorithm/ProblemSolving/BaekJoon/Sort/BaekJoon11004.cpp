//
//  BaekJoon11004.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/18.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    vector<int> a;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    
    sort(a.begin(), a.end());
    
    cout << a[k - 1];
    
    return 0;
}
