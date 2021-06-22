//
//  3986-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/30.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, res;
string str;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;
        stack<char> s;
        for(int j = 0; j < str.size(); j++) {
            if(s.empty()) s.push(str[j]);
            else if(s.top() == str[j]) s.pop();
            else s.push(str[j]);
        }
        if(s.empty())
            res += 1;
    }
    cout << res;
    return 0;
}
