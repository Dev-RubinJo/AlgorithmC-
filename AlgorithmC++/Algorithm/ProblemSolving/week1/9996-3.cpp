//
//  9996-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
string s, temp;
int main(void) {
    cin >> n;
    cin >> s;
    int index = s.find('*');
    string pre = s.substr(0, index);
    string suf = s.substr(index + 1, s.size() - index - 1);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp.size() < s.size() - 1) {
            cout << "NE" << '\n';
            continue;
        }
        string preTemp = temp.substr(0, index);
        string sufTemp = temp.substr(temp.size() - (s.size() - index - 1), s.size() - index - 1);
        if(pre == preTemp && suf == sufTemp) cout << "DA" << '\n';
        else cout << "NE" << '\n';
    }
    return 0;
}
