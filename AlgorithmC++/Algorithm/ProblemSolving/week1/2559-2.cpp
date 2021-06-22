//
//  2559-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/29.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, k, temp, res = INT_MIN;
int arr[100002];
int main(void) {
    cin >> n >> k;
    for(int i = 1; i < n + 1; i++) {
        cin >> temp;
        arr[i] += temp + arr[i - 1];
    }
    for(int i = n; i >= k; i--) {
        if(res < arr[i] - arr[i - k])
            res = arr[i] - arr[i - k];
    }
    cout << res;
    return 0;
}

// MARK: 지금은 res의 초기값이 -10000000이 되야한다는 것을 망각함. 주의할 수 있도록.
