//
//  BaekJoon2752.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/10.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <iostream>
#include <stdio.h>

int main() {
    
    int a[3] = {0, };
    
    int index = 0;
    for(int i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < 3; i++) {
        int min = 1000001;
        for(int j = i; j < 3; j++) {
            if (min > a[j]) {
                min = a[j];
                index = j;
            }
        }
        int temp = a[index];
        a[index] = a[i];
        a[i] = temp;
    }
    
    for(int i = 0; i < 3; i++) {
        std::cout << a[i] << " ";
//        std::cout << a[i]; <- 이런거 하면 안됨
    }
    
    
    return 0;
}
