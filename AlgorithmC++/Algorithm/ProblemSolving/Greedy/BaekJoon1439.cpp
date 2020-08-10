//
//  BaekJoon1439.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/10.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
    int one = 0, zero = 0;
    string str;
    cin >> str;
    
    if(str[0] == '0') zero += 1;
    else one += 1;
    
    for(int i = 0; i < str.size() - 1; i++) {
        if(str[i] != str[i + 1]) {
            if(str[i + 1] == '1') one += 1;
            else zero += 1;
        }
    }
    cout << min(zero, one);
    return 0;
}
