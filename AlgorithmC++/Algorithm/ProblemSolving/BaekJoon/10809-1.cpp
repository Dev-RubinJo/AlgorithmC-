//
//  10809-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/07.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string s;
int a[26];
int main(void) {
    cin >> s;
    fill(&a[0], &a[0] + 26, -1);
    for(int i = 0; i < s.size(); i++) {
        if(a[s[i] - 'a'] == -1) a[s[i] - 'a'] = s.find(s[i]);
    }
    for(int i = 0; i < 26; i++) cout << a[i] << " ";
    return 0;
}
