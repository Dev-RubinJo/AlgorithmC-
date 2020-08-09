//
//  숫자 카드 게임.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/09.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    int max = 0, min = 101;
    cin >> n >> m;
    int cards[100][100];
    
    for(int i = 0; i < n; i++) {
        min = 101;
        for(int j = 0; j < m; j++) {
            cin >> cards[i][j];
            if(cards[i][j] < min) min = cards[i][j];
        }
        if(min > max) max = min;
    }
    
    cout << max;
    
    return 0;
}
