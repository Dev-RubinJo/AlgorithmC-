//
//  2309-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int a[9], cnt;
int main(void) {
    for(int i = 0; i < 9; i++)
        cin >> a[i];
    sort(a, a + 9);
    do {
        for(int i = 0; i < 7; i++) cnt += a[i];
        if(cnt == 100) break;
        else cnt = 0;
    } while(next_permutation(a, a + 9));
    for(int i = 0; i < 7; i++)
        cout << a[i] << '\n';
    return 0;
}
