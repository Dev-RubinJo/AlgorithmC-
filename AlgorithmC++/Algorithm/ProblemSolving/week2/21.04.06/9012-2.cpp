//
//  9012-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int tc = 0; tc < t; tc++) {
        cin >> s;
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(st.empty()) st.push(s[i]);
            else if(!st.empty()) {
                if(st.top() == '(' && s[i] == ')') st.pop();
                else st.push(s[i]);
            }
        }
        if(st.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
