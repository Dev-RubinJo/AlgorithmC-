//
//  BaekJoon11650.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/12.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, b, c;
    vector<pair<int, int> > a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> b >> c;
        a.push_back(pair<int, int>(b, c));
    }
    
    sort(a.begin(), a.end());
    
    for(int i = 0; i < n; i++) {
        cout << a[i].first << " " << a[i].second << "\n";
    }
    
        
    return 0;
}
// 이 문제도 벡터를 알아야 쉽게 풀 수 있는 문제
