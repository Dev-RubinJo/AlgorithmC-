//
//  SelectionSort.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/09.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int a[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    int index = 0;
    
    for(int i = 0; i < 10; i++) {
        int min = 9999;
        for(int j = i; j < 10; j++) {
            if(min > a[j]) {
                min = a[j];
                index = j;
            }
        }
        
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
    
    for(int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

// 1, 10, 5, 8, 7, 6, 4, 3, 2, 9
