//
//  4659-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/03.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
bool isM, flag;
char m[] = {'a', 'e', 'i', 'o', 'u'};
int arr[21];
int main(void) {
    while(1) {
        cin >> s;
        if (s == "end") break;
        fill(&arr[0], &arr[0] + 21, 0); // MARK: 여기부터 조건 2
        arr[0] = 1;
        isM = 0;
        for(int i = 0; i < 5; i++)
            if(s[0] == m[i])
                isM = 1;
        cnt = 1;
        for(int i = 1; i < s.size(); i++) {
            bool tempFlag = 0;
            if(isM) {
                for(int j = 0; j < 5; j++) {
                    if(s[i] == m[j]) {
                        arr[i] = arr[i - 1] + 1;
                        tempFlag = 1;
                        break;
                    }
                }
                if(!tempFlag) {
                    isM = 0;
                    arr[i] = 1;
                }
            } else {
                for(int j = 0; j < 5; j++) {
                    if(s[i] == m[j]) {
                        arr[i] = 1;
                        tempFlag = 1;
                        break;
                    }
                }
                if(tempFlag) {
                    isM = 1;
                } else {
                    arr[i] = arr[i - 1] + 1;
                }
            }
            cnt = max(arr[i], cnt);
        }
        flag = 0; // MARK: 여기부터 조건 3
        for(int i = 1; i < s.size(); i++) {
            if(s[i - 1] == 'e' && s[i] == 'e') continue;
            else if(s[i - 1] == 'o' && s[i] == 'o') continue; // MARK: 처음에 오타내서 실패
            else if(s[i - 1] == s[i]) {
                flag = 1;
                break;
            }
        }
        isM = 0; // MARK: 여기부터 조건 1
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < 5; j++) {
                if(s[i] == m[j]) {
                    isM = 1;
                    break;
                }
            }
        }
        cout << "<" << s << "> is ";
        if(isM && !flag && cnt < 3) {
            cout << "acceptable." << '\n';
        } else {
            cout << "not acceptable." << '\n';
        }
    }
    return 0;
}
