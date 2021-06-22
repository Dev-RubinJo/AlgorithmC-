//
//  2870-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v;
bool cmp(string a, string b) {
    if(a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        string temp = "";
        for(int j = 0; j < s.size(); j++) {
            if(s[j] >= 'a' && s[j] <= 'z') {
                if(temp != "") {
                    v.push_back(temp);
                    temp = "";
                }
            } else {
                temp += string(1, s[j]);
            }
        }
        if(temp != "") {
            v.push_back(temp);
        }
    }
    for(int j = 0; j < v.size(); j++) {
        for(int i = 0; i < v[j].size() - 1; i++) {
            if(v[j][i] == '0' && i != v[j].size() - 1) {
                v[j].erase(0, 1);
                i -= 1;
            } else break;
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto a: v)
        cout << a << '\n';
    return 0;
}
