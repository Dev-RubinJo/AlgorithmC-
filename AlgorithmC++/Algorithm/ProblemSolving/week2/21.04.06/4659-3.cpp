//
//  4659-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int flag, jcnt, mcnt;
string s;
bool isM(int c) {
    return (c == 0) || (c == 4) || (c == 8) || (c == 14) || (c == 20);
}
int main(void) {
    while(1) {
        cin >> s;
        flag = 0; jcnt = 0; mcnt = 0;
        if(s == "end") break;
        for(int i = 0; i < s.size(); i++) {
            if(isM(s[i] - 'a')) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            for(int i = 0; i < s.size(); i++) {
                if(isM(s[i] - 'a')) { mcnt += 1; jcnt = 0; }
                else { mcnt = 0; jcnt += 1; }
                if(jcnt > 2 || mcnt > 2) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) {
            for(int i = 1; i < s.size(); i++) {
                if(s[i] == s[i - 1] && s[i] == 'e') continue;
                if(s[i] == s[i - 1] && s[i] == 'o') continue;
                if(s[i] == s[i - 1]) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) cout << "<" + s + "> is acceptable.\n";
        else cout << "<" + s + "> is not acceptable.\n";
    }
    return 0;
}
