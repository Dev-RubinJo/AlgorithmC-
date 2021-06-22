//
//  3986-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/28.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, cnt;
string s;
stack<char> st;

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            if (st.empty())
                st.push(s[j]);
            else if(st.top() == s[j])
                st.pop();
            else
                st.push(s[j]);
        }
        if(st.empty()) cnt += 1;
        while(!st.empty())
            st.pop();
    }
    cout << cnt;
    return 0;
}
// MARK: 스택 공부 더 하기
