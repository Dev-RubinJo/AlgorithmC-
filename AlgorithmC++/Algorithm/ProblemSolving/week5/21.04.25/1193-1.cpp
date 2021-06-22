//
//  1193-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int x, cnt = 0, multi = 1;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> x;
    while(1) {
        if(x - multi <= 0) break;
        x -= multi;
        multi += 1;
        cnt += 1;
    }
    if(cnt % 2)
        cout << x << "/" << cnt + 2 - x;
    else
        cout << cnt + 2 - x << "/" << x;
    return 0;
}
// TODO: 꼭 다시 풀어보기
