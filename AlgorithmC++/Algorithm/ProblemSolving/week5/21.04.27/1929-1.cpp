//
//  1929-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/27.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
long long n, m;
bool a[1000002];
void check() {
    for(long long i = 2; i <= n; i++) {
        a[i] = 1;
    }
    for(long long i = 2; i <= n; i++) {
        if(!a[i]) continue;
        for(long long j = i * i; j <= n; j += i) {
            a[j] = 0;
        }
    }
}
int main(void) {
    cin >> m >> n;
    check();
    for(long long i = m; i <= n; i++) {
        if(a[i]) cout << i << '\n';
    }
    return 0;
}
