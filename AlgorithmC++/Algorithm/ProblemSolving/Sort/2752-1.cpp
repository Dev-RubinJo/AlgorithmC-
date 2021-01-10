//
//  2752-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/01/10.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <iostream>

int main(void) {
    
    int a[3] = {0, };
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < 3; j++) {
            if (a[j - 1] > a[j]) {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        std::cout << a[i] << ' ';
    }
    
    return 0;
}
