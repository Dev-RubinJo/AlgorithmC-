//
//  1213-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/29.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string s;
int alphas[26], oddCnt, oddIndex;
int main(void) {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        alphas[s[i] - 'A'] += 1;
    }
    for(int i = 0; i < 26; i++) {
        if(alphas[i] % 2) {
            oddCnt += 1;
            oddIndex = i;
        }
    }
    if(oddCnt > 1) {
        cout << "I'm Sorry Hansoo" << '\n';
    } else {
        for(int i = 0; i < 26; i++) { // MARK: 처음에 숫자 범위를 25전까지로 돌려서 계속 틀림, 이유도 못찾은 멍청이. 26 전까지로 바꾸니 통과
            int length = alphas[i];
            for(int j = 0; j <  length / 2; j++) {
                cout << (char)(i + 'A');
                alphas[i] -= 1;
            }
        }
        if(oddCnt != 0) {
            cout << (char)(oddIndex + 'A');
            alphas[oddIndex] -= 1;
        }
        for(int i = 25; i >= 0; i--) {
            while(alphas[i] > 0) {
                cout << (char)(i + 'A');
                alphas[i] -= 1;
            }
        }
    }
    return 0;
}
