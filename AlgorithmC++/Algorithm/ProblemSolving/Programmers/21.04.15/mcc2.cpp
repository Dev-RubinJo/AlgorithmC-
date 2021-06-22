//
//  mcc2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/15.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.size(); i++) {
        stack<char> st;
        for(int j = 0; j < s.size(); j++) {
            if(st.empty()) {
                st.push(s[j]);
            } else {
                if(st.top() == '(' && s[j] == ')') st.pop();
                else if(st.top() == '[' && s[j] == ']') st.pop();
                else if(st.top() == '{' && s[j] == '}') st.pop();
                else st.push(s[j]);
            }
        }
        if(st.empty()) answer += 1;
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    return answer;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution("[](){}");
    return 0;
}
