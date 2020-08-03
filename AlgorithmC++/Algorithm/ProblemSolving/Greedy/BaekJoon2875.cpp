//
//  BaekJoon2875.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/02.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
    int n, m, k;
    
    cin >> n >> m >> k;
    cout << min(min(n / 2, m), (n + m - k) / 3);
    return 0;
}

/*   // 틀린 코드
int main(void) {
    int n, m, k;
    
    cin >> n >> m >> k;
    if(n - 2 * m >= k) {
        cout << m;
    } else if (n != 1) {
        while(n - 2 * m < k && k != 0) {
            if(k > 1 && n > m) {
                n -= 1;
                m -= 1;
                k -= 2;
            } else {
                m -= 1;
                k -= 1;
            }
        }
        cout << m;
    } else {
        cout << 0;
    }
    
    return 0;
}
*/
