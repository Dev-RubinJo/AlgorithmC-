//
//  11653-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/27.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
int main(void) {
    cin >> n;
    for(int i = 2; i <= sqrt(n); i++) {
        while(n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
    if(n != 1) cout << n;
    return 0;
}
