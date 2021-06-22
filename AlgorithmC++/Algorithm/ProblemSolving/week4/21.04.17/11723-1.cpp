//
//  11723-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/17.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, s, t;
string st;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> st;
        if(st != "all" && st != "empty")
            cin >> t;
        if(st == "add") {
            if(!(s & (1 << (t - 1))))
                s |= (1 << (t - 1));
        } else if(st == "check") {
            if(s & (1 << (t - 1))) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if(st == "remove") {
            s &= ((1 << 21) - 1) - (1 << (t - 1));
        } else if(st == "toggle") {
            if(!(s & (1 << (t - 1)))) {
                s |= (1 << (t - 1));
            } else {
                s &= ((1 << 21) - 1) - (1 << (t - 1));
            }
        } else if(st == "all") {
            s |= (1 << 21) - 1;
        } else if(st == "empty") {
            s &= 0;
        }
    }
    return 0;
}
