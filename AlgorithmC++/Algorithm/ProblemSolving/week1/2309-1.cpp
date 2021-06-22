//
//  2309  d-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int nanjang[9], fake[2], totalSum = 0;
int main() {
    for(int i = 0; i < 9; i++) {
        cin >> nanjang[i];
        totalSum += nanjang[i];
    }
    sort(nanjang, nanjang + 9);
    for(int i = 0; i < 9; i++) {
        for(int j = i + 1; j < 9; j++) {
            if(totalSum - (nanjang[i] + nanjang[j]) == 100) {
                fake[0] = i; fake[1] = j;
            }
        }
    }
    for(int i = 0; i < 9; i++) {
        if(i != fake[0] && i != fake[1]) {
            cout << nanjang[i] << '\n';
        }
    }
    
    return 0;
}
