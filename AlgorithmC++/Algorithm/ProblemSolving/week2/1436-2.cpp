//
//  1436-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/05.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, res;
int main(void) {
    cin >> n;
    string s = "666";
    while(n > 0) {
        if(to_string(res).find("666") != string::npos) n -= 1;
        res += 1;
    }
    cout << res - 1;
    return 0;
}
