//
//  2559-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

// MARK: 누적합을 이용한 문제
#include <bits/stdc++.h>
using namespace std;

int n, k, temp, maxVal = -1316134911;
int temper[100001];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        temper[i] = temper[i - 1] + temp;
    }
    for(int i = k; i <= n; i++)
        if(maxVal < (temper[i] - temper[i - k]))
            maxVal = temper[i] - temper[i - k];
    cout << maxVal;
    return 0;
}
