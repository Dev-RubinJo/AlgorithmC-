//
//  주식가격-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/14.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int ans[100001][2];
vector<int> solution(vector<int> prices) {
    const int n = prices.size();
    vector<int> answer(n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && prices[st.top()] > prices[i]) {
            int top = st.top();
            st.pop();
            answer[top] = i - top;
        }
        st.push(i);
    }
    while(!st.empty()) {
        int top = st.top();
        st.pop();
        answer[top] = n - 1 - top;
    }
    return answer;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> a = solution({1, 2, 3, 2, 3});
    for(int a1: a)
        cout << a1 << endl;
    return 0;
}
