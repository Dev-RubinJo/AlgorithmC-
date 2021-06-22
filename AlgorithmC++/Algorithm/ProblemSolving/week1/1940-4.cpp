//
//  1940-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, a[15001], res;
int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int f = 0, l = n - 1;
    while(f < l) {
        if(a[f] + a[l] == m) {
            res += 1; f += 1; l -= 1;
        } else if (a[f] + a[l] < m) f += 1;
        else l -= 1;
    }
    cout << res;
    return 0;
}
