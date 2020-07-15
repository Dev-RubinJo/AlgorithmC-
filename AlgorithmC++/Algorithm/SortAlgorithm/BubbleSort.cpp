//
//  BubbleSort.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/09.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int a[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 9 - i; j++) {
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    // 내 코드, 나동빈씨와 동일
    
    for(int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
