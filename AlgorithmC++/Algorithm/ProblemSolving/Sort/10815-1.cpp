//
//  10815-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/01/18.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <iostream>

int arr[20000001] = {0, };

using namespace std;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 0, m = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[temp + 10000000] = 1;
    }
    cin >> m;

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        if (arr[temp + 10000000]) cout << 1 << " ";
        else cout << 0 << " ";
    }
    return 0;
}
