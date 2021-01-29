//
//  1406-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/01/28.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;
    int n;
    cin >> n;
    
    list<char> lst(str.begin(), str.end());
    auto pointer = lst.end();
    for (int i = 0; i < n; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (pointer == lst.begin()) continue;
            else pointer--;
        } else if (cmd == 'D') {
            if (pointer == lst.end()) continue;
            else pointer++;
        } else if (cmd == 'B') {
            if (pointer == lst.begin()) continue;
            else lst.erase(--pointer);
        } else if (cmd == 'P') {
            char x;
            cin >> x;
            lst.insert(pointer, x);
        }
    }
    
    for (auto &x: lst) {
        cout << x;
    }
    
    return 0;
}
