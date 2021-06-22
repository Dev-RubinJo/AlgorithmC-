//
//  12813-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/10.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
string a, b;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for(int i = 0; i < 100000; i++) {
        cout << (stoi(a.substr(i, 1)) & stoi(b.substr(i, 1)));
    }
    cout << endl;
    for(int i = 0; i < 100000; i++) {
        cout << (stoi(a.substr(i, 1)) | stoi(b.substr(i, 1)));
    }
    cout << endl;
    for(int i = 0; i < 100000; i++) {
        cout << (stoi(a.substr(i, 1)) ^ stoi(b.substr(i, 1)));
    }
    cout << endl;
    for(int i = 0; i < 100000; i++) {
        cout << (!stoi(a.substr(i, 1)));
    }
    cout << endl;
    for(int i = 0; i < 100000; i++) {
        cout << (!stoi(b.substr(i, 1)));
    }
    cout << endl;
    return 0;
}
