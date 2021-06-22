//
//  2979-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int t[102], a, b, c, res, temp1, temp2;
int main(void) {
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++) {
        cin >> temp1 >> temp2;
        for(int j = temp1; j < temp2; j++) t[j] += 1;
    }
    for(int i = 0; i < 101; i++) {
        if(t[i] == 1) res += a;
        else if(t[i] == 2) res += 2 * b;
        else if(t[i] == 3) res += 3 * c;
    }
    cout << res;
    return 0;
}
