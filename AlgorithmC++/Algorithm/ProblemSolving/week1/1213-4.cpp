//
//  1213-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int flag, a[26], oddIndex = -1;
string s;
int main(void) {
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        a[s[i] - 'A'] += 1;
    for(int i = 0; i < 26; i++) {
        if(a[i] % 2) {
            oddIndex = i;
            flag += 1;
        }
        if(flag > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < a[i] / 2; j++)
            cout << (char)(i + 'A');
    }
    if(oddIndex != -1)
        cout << (char)(oddIndex + 'A');
    for(int i = 25; i >= 0; i--) {
        for(int j = 0; j < a[i] / 2; j++)
            cout << (char)(i + 'A');
    }
    return 0;
}
