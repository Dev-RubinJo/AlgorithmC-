//
//  1436-l.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/08.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
int n, name = 666;
int main(void) {
    cin >> n;
    while(n > 0) {
        if(to_string(name).find("666") != string::npos) n -= 1;
        if(!n) break;
    }
    cout << name;
    return 0;
}
