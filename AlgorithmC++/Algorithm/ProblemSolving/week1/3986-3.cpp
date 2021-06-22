//
//  3986-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, res;
string s;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(st.empty() || st.top() != s[i]) st.push(s[i]);
            else if (st.top() == s[i]) st.pop();
        }
        if(st.empty()) res += 1;
    }
    cout << res;
    return 0;
}
