//
//  4659-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string s;
char ch[] = {'a', 'e', 'i', 'o', 'u'};
int isM, cnt, flag;
int main(void) {
    while(1) {
        cin >> s;
        if(s == "end") break;
        isM = 0;
        cnt = 1;
        for(int i = 0; i < 5; i++)
            if(s[0] == ch[i])
                isM = 1;
        for(int i = 1; i < s.size(); i++) {
            for(int j = 0; j < 5; j++) {
                if(s[i] == ch[j]) {
                    if(!isM) {
                        isM = 1;
                        cnt = 1;
                    } else cnt += 1;
                    flag = 1;
                    break;
                } else flag = 0;
            }
            if(!flag) {
                if(isM) {
                    cnt = 1;
                } else if(!isM) {
                    cnt += 1;
                }
                isM = 0;
            }
            if(cnt > 2) break;
        }
        isM = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < 5; j++) {
                if(s[i] == ch[j]) {
                    isM = 1;
                    break;
                }
            }
        }
        flag = 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[i - 1] == s[i] && s[i] == 'e') continue;
            else if(s[i - 1] == s[i] && s[i] == 'o') continue;
            else if(s[i - 1] == s[i]) {
                flag = 1;
                break;
            }
        }
        cout << "<" + s + "> is ";
        if(cnt < 3 && isM && !flag) cout << "acceptable.\n";
        else cout << "not acceptable.\n";
    }
    return 0;
}
