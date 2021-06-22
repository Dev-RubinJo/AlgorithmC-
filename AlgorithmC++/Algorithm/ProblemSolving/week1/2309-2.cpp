//
//  2309-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/28.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int arrays[9];
int res;

int main(void) {
    for(int i = 0; i < 9; i++) {
        cin >> arrays[i];
    }
    sort(arrays, arrays + 9);
    do {
        for(int i = 0; i < 7; i++) res += arrays[i];
        if(res == 100) break;
        res = 0;
    } while(next_permutation(arrays, arrays + 9));
    for(int i = 0; i < 7; i++) {
        cout << arrays[i] << '\n';
    }
    return 0;
}
