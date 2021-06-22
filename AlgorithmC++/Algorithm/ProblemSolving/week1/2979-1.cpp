//
//  2979-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int ts[101], a, b, c;
int temp1, temp2, res = 0;
int main() {
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++) {
        cin >> temp1 >> temp2;
        for(int j = temp1; j < temp2; j++) {
            ts[j] += 1;
        }
    }
    
    for(int i = 1; i < 101; i++) {
        if(ts[i] == 1)
            res = res + ts[i] * a;
        else if(ts[i] == 2)
            res = res + ts[i] * b;
        else if(ts[i] == 3)
            res = res + ts[i] * c;
    }
    cout << res;
    return 0;
}

