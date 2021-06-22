//
//  2870-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
string s;
bool cmp(string a, string b) {
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        string temp = "";
        for(int j = 0; j < s.size(); j++) {
            if(s[j] - '0' >= 0 && s[j] - '0' <= 9) {
                temp += string(1, s[j]);
            } else {
                if(temp == "") continue;
                else {
                    v.push_back(temp);
                    temp = "";
                }
            }
        }
        if(temp != "") v.push_back(temp);
    }
    for(int i = 0; i < v.size(); i++) {
        for(int k = 0; k < v[i].size() - 1; k++) {
            if(v[i][k] - '0' != 0) break;
            v[i].erase(v[i].begin() + k);
            k -= 1;
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto a: v)
        cout << a << '\n';
    return 0;
}
