//
//  BaekJoon2884.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/11.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>

int main() {
    
    int h, m;
    scanf("%d %d", &h, &m);
    
    m = m - 45;
    if(m < 0) {
        h = h - 1;
        m = m + 60;
        if(h < 0) {
            h = h + 24;
        }
    }
    printf("%d %d", h, m);
    return 0;
}
