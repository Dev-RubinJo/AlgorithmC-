//
//  9996-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/29.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
string str, temp;
int main(void) {
    cin >> n;
    cin >> str;
    int length = str.size() - str.find('*') - 1;
    string pre = str.substr(0, str.find('*'));
    string suf = str.substr(str.find('*') + 1, length);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp.size() >= str.size() - 1) {
            string preTemp = temp.substr(0, str.find('*'));
            string sufTemp = temp.substr(temp.size() - length, length);
            if((pre == preTemp) && (suf == sufTemp))
                cout << "DA" << '\n';
            else
                cout << "NE" << '\n';
        } else
            cout << "NE" << '\n';
    }
    
    return 0;
}
