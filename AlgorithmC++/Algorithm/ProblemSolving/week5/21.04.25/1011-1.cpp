//
//  1011-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int tc, x, y, k;
long long d;
int main(void) {
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        long long i = 1;
        cin >> x >> y;
        d = y - x;
        while(1) {
            if(i * i > d) break;
            i += 1;
        }
        if(pow(i - 1, 2) == y - x)
            cout << 2 * i - 3 << '\n';
        else if((pow(i, 2) + pow(i - 1, 2)) / 2 >= y - x)
            cout << 2 * (i - 1) << '\n';
        else
            cout << 2 * (i - 1) + 1 << '\n';
    }
    
    return 0;
}
// MARK: 참고 코드 - https://aorica.tistory.com/126
// MARK: 꼭 다시 풀어보기
