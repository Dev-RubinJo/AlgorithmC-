//
//  1159-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string s;
int a[26], n, cnt;
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        a[s[0] - 'a'] += 1;
        if(a[s[0] - 'a'] >= 5) cnt += 1;
    }
    if(cnt) {
        for(int i = 0; i < 26; i++) {
            if(a[i] >= 5) cout << (char)(i + 'a');
        }
    } else {
        cout << "PREDAJA";
    }
    return 0;
}
