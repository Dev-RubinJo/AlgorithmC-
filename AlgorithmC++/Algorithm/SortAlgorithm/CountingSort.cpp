//
//  CountingSort.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/14.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    
    int a[30] = {1, 3, 2, 4, 3, 2, 5, 3, 1, 2, 3, 4, 4, 3, 5, 1, 2, 3, 5, 2, 3, 1, 4, 3, 5, 1, 2, 1, 1, 1};
    int temp[5] = {0, };
    
    for(int i = 0; i < 30; i++) {
        temp[a[i] - 1]++;
    }
    
    for(int i = 0; i < 5; i++) {
        while(temp[i] > 0) {
            cout << i + 1;
            temp[i]--;
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}
