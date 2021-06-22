//
//  2870-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/03.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
string s;
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
                if (temp.size()) {
                    v.push_back(temp);
                    temp = "";
                }
            } else {
                if(!temp.size()) temp = string(1, s[j]);
                else temp = temp + string(1, s[j]);
            }
        }
        if (temp.size())
            v.push_back(temp);
    }
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            if(v[i][j] == '0' && j != v[i].size() - 1) {
                v[i].erase(v[i].begin() + j);
                j -= 1;
            } else break;
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto ve: v)
        cout << ve << "\n";
    return 0;
}
/*
 #include <bits/stdc++.h>
 using namespace std;
 int n;
 vector<string> v;
 string s;
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
                 if (temp.size()) {
                     for(int k = 0; k < temp.size() - 1; k++) {
                         if(temp[k] == '0')
                             temp = temp.substr(1);
                         else break;
                     }
                     v.push_back(temp);
                     temp = "";
                 }
             } else {
                 if(!temp.size()) temp = string(1, s[j]);
                 else temp = temp + string(1, s[j]);
             }
         }
         if (temp.size()) {
             for(int k = 0; k < temp.size() - 1; k++) {
                 if(temp[k] == '0') {
                     temp = temp.substr(1);
                     k -= 1;
                 } else break;
             }
             v.push_back(temp);
         }
     }
     sort(v.begin(), v.end(), cmp);
     for(auto ve: v)
         cout << ve << "\n";
     return 0;
 }
 */
