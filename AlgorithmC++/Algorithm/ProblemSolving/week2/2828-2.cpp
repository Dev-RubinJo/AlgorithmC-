//
//  2828-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/02.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, apple, num, res, f, l;
int main(void) {
    cin >> n >> m;
    f = 1; l = m;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> apple;
        if(apple < f) {
            res += abs(apple - f);
            f = apple; l = f + m - 1;
        } else if (apple > l) {
            res += abs(l - apple);
            l = apple; f = l - m + 1;
        }
    }
    cout << res;
    return 0;
}
