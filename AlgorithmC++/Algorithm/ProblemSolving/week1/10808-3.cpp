//
//  10808-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int a[26];
string s;
int main(void) {
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        a[s[i] - 'a'] += 1;
    for(int i = 0; i < 26; i++) cout << a[i] << ' ';
    return 0;
}
