//
//  BaekJoon1302.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/07.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
    int n, maxVal = 0;
    string book;
    map<string, int> books;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> book;
        books[book] += 1;
    }
    
    for(map<string, int>::iterator it = books.begin(); it != books.end(); it++) { // --> map을 vector로 치환해서 sort를 써도 되긴 하다
        if(maxVal < it->second) {
            maxVal = it->second;
            book = it->first;
        }
    }
    
    cout << book;
    
    return 0;
}
