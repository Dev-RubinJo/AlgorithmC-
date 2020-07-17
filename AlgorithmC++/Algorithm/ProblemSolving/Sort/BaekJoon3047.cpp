//
//  BaekJoon3047.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/18.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    
    int a[3] = {0, };
    int c[3] = {0, };
    
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 3; i++) {
        char temp;
        cin >> temp;
        c[i] = temp - 'A';
    }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2 - i; j++) {
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
    for(int i = 0; i < 3; i++) {
        cout << a[c[i]] << " "; 
    }
    
    
    return 0;
}
