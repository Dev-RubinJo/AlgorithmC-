//
//  9996-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int n;
string strings[102];
string gijun;

int main() {
    
    cin >> n;
    cin >> gijun;
    for(int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    
    int index = gijun.find("*");
    string pre = gijun.substr(0, index);
    string suf = gijun.substr(index + 1, gijun.size() - index - 1);
    
    for(int i = 0; i < n; i++) {
        if(strings[i].size() < gijun.size() - 1) {
            cout << "NE" << '\n';
            continue;
        }
        string preTemp = strings[i].substr(0, index);
        string sufTemp = strings[i].substr(strings[i].size() - (gijun.size() - index - 1), gijun.size() - index - 1);
        if(preTemp == pre && suf == sufTemp)
            cout << "DA" << '\n';
        else
            cout << "NE" << '\n';
    }
    
    return 0;
}
