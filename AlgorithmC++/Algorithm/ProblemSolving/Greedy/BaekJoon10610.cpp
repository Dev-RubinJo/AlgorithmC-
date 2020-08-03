//
//  BaekJoon10610.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/02.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int temp = 0;
    string num;
    cin >> num;
    
    sort(num.begin(), num.end());
//    cout << num[0];
    if(num[0] != '0') {
        cout << -1;
        return 0;
    }
    for(int i = 1; i < num.size(); i++) {
        temp += num[i] - '0';
    }
    
    if(temp % 3 != 0) {
        cout << -1;
        return 0;
    } else {
        for(int i = num.size() - 1; i >= 0; i--)
            cout << num[i];
    }
    
    return 0;
}
