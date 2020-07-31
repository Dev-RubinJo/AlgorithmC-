//
//  BaekJoon16435.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/31.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n, l;
    cin >> n >> l;
    int h[1001] = {0, };
    for(int i = 0; i < n; i++)
        cin >> h[i];
    
    sort(h, h + n);
    
    for(int i = 0; i < n; i++) {
        if(h[i] <= l) {
            l += 1;
        } else {
            break;
        }
    }
    
    cout << l;
    
    return 0;
}
