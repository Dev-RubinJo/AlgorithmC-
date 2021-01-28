//
//  BaekJoon1377.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/12.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, answer = 0;
    cin >> n;
    vector<pair<int, int> > a(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
        answer = max(answer, a[i].second - i);
    
    cout << answer + 1;
    
    return 0;
}
