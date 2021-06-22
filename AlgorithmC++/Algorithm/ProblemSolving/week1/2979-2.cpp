//
//  2979-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/28.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int arrays[101];
int a, b, c, temp1, temp2, res;

int main(void) {
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++) {
        cin >> temp1 >> temp2;
        for(int i = temp1; i < temp2; i++) {
            arrays[i] += 1;
        }
    }
    for(int i = 1; i < 101; i++) {
        if (arrays[i] == 1) {
            res += a;
        } else if (arrays[i] == 2) {
            res += b * 2;
        } else if (arrays[i] == 3) {
            res += c * 3;
        }
    }
    cout << res;
    return 0;
}
