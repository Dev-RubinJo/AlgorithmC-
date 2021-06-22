//
//  4949-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string s;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    while(1) {
        getline(cin, s);
        if(s == ".") break;
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '(' && s[i] != '[' && s[i] != ')' && s[i] != ']') continue;
            if(st.empty()) st.push(s[i]);
            else if(!st.empty()) {
                if(st.top() == '(' && s[i] == ')') st.pop();
                else if(st.top() == '[' && s[i] == ']') st.pop();
                else st.push(s[i]);
            }
        }
        if(st.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
