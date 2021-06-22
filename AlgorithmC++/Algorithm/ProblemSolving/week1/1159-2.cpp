//
//  1159-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/28.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, flag;
int strs[26];
string temp;
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        strs[temp[0] - 'a'] += 1;
    }
    for(int i = 0; i < 26; i++) {
        if(strs[i] >= 5) {
            cout << (char)(i + 'a');
            flag = 1;
        }
    }
    if(!flag) cout << "PREDAJA";
    
    return 0;
}
