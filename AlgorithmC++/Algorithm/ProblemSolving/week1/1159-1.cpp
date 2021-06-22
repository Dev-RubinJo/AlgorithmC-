//
//  1159-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

string s;
int n, alphas[26], flag = 0;

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        alphas[s[0] - 'a'] += 1;
    }
    
    for(int i = 0; i < 26; i++) {
        if(alphas[i] >= 5) { // 아직 이런 주의가 필요하다 처음에 >라고만 해서 틀림
            flag = 1;
            cout << (char)(i + 'a');
        }
    }
    if (!flag) {
        cout << "PREDAJA";
    }
        
    return 0;
}
