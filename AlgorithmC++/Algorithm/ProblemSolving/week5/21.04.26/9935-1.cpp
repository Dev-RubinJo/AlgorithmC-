//
//  9935-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string s, b;
deque<char> dq;
void check() {
    if(dq.size() < b.size()) return;
    string temp;
    for(int i = 0; i < b.size(); i++) {
        temp += string(1, dq.back()); dq.pop_back();
    }
    reverse(temp.begin(), temp.end());
    if(temp == b) return;
    for(int i = 0; i < b.size(); i++) {
        dq.push_back(temp[i]);
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> b;
    for(int i = 0; i < s.size(); i++) {
        dq.push_back(s[i]);
        if(dq.back() == b[b.size() - 1])
            check();
    }
    if(dq.empty()) cout << "FRULA";
    else {
        while(!dq.empty()) {
            cout << dq.front(); dq.pop_front();
        }
    }
    return 0;
}
