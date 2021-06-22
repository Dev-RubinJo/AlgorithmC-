//
//  10250-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int tc, h, w, n, room, f;
int main(void) {
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> h >> w >> n;
        if(!(n % h)) {
            cout << h * 100 + n / h;
        } else {
            room = n / h + 1;
            f = n - (h * (room - 1));
            cout << f * 100 + room;
        }
        cout << '\n';
    }
    return 0;
}
// MARK: 생각이 깊어지는 문제. room이 10을 넘어가냐 안넘어가냐로 0을 붙이지 말고 그냥 f에 100을 곱해서 더하면 되는 문제. 또한 n이 h의 배수일 경우도 예외처리해줘야하는 문제
