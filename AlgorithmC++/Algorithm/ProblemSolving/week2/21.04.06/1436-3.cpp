//
//  1436-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, res = 666;
int main(void) {
    cin >> n;
    while(n > 0) {
        if(to_string(res).find("666") != string::npos) n -= 1;
        res += 1;
    }
    cout << res - 1;
    return 0;
}
