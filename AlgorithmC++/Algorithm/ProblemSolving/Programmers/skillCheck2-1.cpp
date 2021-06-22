//
//  skillCheck2-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/05.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;

bool solution(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        if(st.empty() || s[i] == '(') st.push(s[i]);
        else if(!st.empty() && st.top() == '(' && s[i] == ')') st.pop();
    }
    return (st.empty()) ? true : false;
}
int main(void) {
    cout << solution("()()") << '\n';
    cout << solution("(())()") << '\n';
    cout << solution(")()(") << '\n';
    cout << solution("(()(") << '\n';
    return 0;
}
