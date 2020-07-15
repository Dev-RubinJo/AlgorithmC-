//
//  BaekJoon1181.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/14.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b) {
    if(a.size() < b.size())
        return true;
    else if(a.size() > b.size())
        return false;
    else
        return a < b;
}

int main() {
    string str[20000];
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    
    sort(str, str + n, compare);
    for(int i = 0; i < n; i++) {
        if(i + 1 < n && str[i] == str[i + 1]) {
            continue;
        }
        cout << str[i] << endl;
    }
    
    return 0;
}
// stl sort를 쓰면 편한
