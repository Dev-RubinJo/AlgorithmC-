//
//  P2072.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/01.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        int temp, ans = 0;
        for(int j = 0; j < 10; j++) {
            cin >> temp;
            if(temp % 2 == 1) {
                ans += temp;
            }
        }
        
        cout << "#" << i + 1 << " " << ans << "\n";
    }
    
    return 0;
}
