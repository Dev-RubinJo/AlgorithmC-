//
//  1769-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/01/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    
    cin >> str;
    int count = 0;
    
    while(str.size() > 1) {
        long long temp = 0;
        for (int i = 0; i < str.size(); i++) {
            temp += str[i] - '0';
        }
        str = to_string(temp);
        count += 1;
    }
    cout << count << '\n';
    if (stoi(str) % 3 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}
