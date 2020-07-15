//
//  InsertionSort.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/09.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int a[10] = {10, 1, 5, 8, 7, 6, 4, 3, 2, 9};
    
    for(int i = 0; i < 9; i++) {
        int j = i;
        while(a[j] > a[j + 1]) {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            j--;
        }
    }
    
    for(int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

// MARK: - 삽입정렬 설명
/*
각 숫자를 적절한 위치에 삽입하는 방법
 삽입이라고 얘기는 하지만 결국 뒤에서부터 크기대로 앞으로 이동하면서 버블정렬처럼 바꾸는 기법이다.
 쉽게 말하자면 버블 정렬을 언제 멈출지 알고 있는 정렬
*/
