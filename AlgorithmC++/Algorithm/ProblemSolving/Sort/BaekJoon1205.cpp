//
//  BaekJoon1205.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/25.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    
    int n, score, p, answer = 0;
    cin >> n >> score >> p;
    
    vector<int> a(n);
//    vector<int> pList(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n == p && a[n - 1] >= score) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(a[i] > score) answer += 1;
    }
    answer += 1;
    
    
    cout << answer;
    return 0;
}
