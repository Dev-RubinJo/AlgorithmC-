//
//  1213-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/27.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string str;
int cnt;
char c;
map<char, int> _map;
int main(void) {
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        _map[str[i]] += 1;
    }
    for(map<char, int>::iterator it = _map.begin(); it != _map.end(); it++) {
        if(it->second % 2 == 1) {
            cnt += 1;
            c = it->first;
        }
        if(cnt > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }
    for(map<char, int>::iterator it = _map.begin(); it != _map.end(); it++) {
        if(it->first != c) {
            for(int i = 0; i < it->second / 2; i++) {
                cout << it->first;
            }
        }
        if(it->first == c && it->second > 1) { // MARK: 이런 처리
            for(int i = 0; i < it->second / 2; i++) {
                cout << it->first;
            }
        }
    }
    if(cnt == 1) {
        cout << c;
    }
    for(map<char, int>::reverse_iterator it = _map.rbegin(); it != _map.rend(); it++) {
        if(it->first != c) {
            for(int i = 0; i < it->second / 2; i++) {
                cout << it->first;
            }
        }
        if(it->first == c && it->second > 1) { // MARK: 이런 처리
            for(int i = 0; i < it->second / 2; i++) {
                cout << it->first;
            }
        }
    }
    
    return 0;
}
