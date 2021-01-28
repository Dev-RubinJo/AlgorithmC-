//
//  2750-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/01/10.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <iostream>

int main(void) {
    
    int n;
    int arr[1001];
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << '\n';
    }
    
    return 0;
}
