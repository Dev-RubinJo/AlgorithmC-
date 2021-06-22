//
//  1620-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int n, m;
string temp;
map<string, int> stringKey;
map<int, string> intKey;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        stringKey[temp] = i;
        intKey[i] = temp;
    }
    for(int i = 0; i < m; i++) {
        cin >> temp;
        if (temp[0] >= '0' && temp[0] <= 57)
            cout << intKey[stoi(temp)] << '\n';
        else {
            cout << stringKey[temp] << '\n';
        }
    }
    return 0;
}
