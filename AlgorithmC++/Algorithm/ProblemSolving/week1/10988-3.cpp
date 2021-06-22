//
//  10988-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string s, temp;
int main(void) {
    cin >> s;
    temp = s;
    reverse(temp.begin(), temp.end());
    if(s == temp) cout << 1;
    else cout << 0;
    return 0;
}
