//
//  11721-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/07.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(void) {
    cin >> s;
    while(n < s.size()) {
        cout << s.substr(n, 10) << '\n';
        n += 10;
    }
    return 0;
}
