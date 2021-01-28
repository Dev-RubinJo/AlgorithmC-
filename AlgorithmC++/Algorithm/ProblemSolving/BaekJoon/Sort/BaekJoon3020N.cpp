//
//  BaekJoon3020.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/23.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    
    int n, h;
    vector<int> dis;
    int a[500000] = {0, };
    int minValue = 500000, countValue = 0;
    cin >> n >> h;
    
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        dis.push_back(temp);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < h; j++) {
            if(i % 2 == 0) {
                if(j >= h - dis[i])
                    a[j] += 1;
            } else {
                if(j < dis[i])
                    a[j] += 1;
            }
        }
    }
    
    for(int i = 0; i < h; i++) {
        if(minValue > a[i]) {
            minValue = a[i];
            countValue = 1;
        } else if(minValue == a[i])
            countValue += 1;
    }
    
    cout << minValue << " " << countValue;
    
    return 0;
}
// 이분탐색으로 해야하는 문제
