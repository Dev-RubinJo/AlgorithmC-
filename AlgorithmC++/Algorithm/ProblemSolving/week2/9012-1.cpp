//
//  9012-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int tc;
string str;
int main(void) {
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        cin >> str;
        stack<char> s;
        for(int j = 0; j < str.size(); j++) {
            if(s.empty() || str[j] == '(' || s.top() == ')') s.push(str[j]);
            else if(s.top() == '(' && str[j] == ')') s.pop();
        }
        if(s.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
