//
//  2581-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, sum, minp = INT_MAX;
int a[10001];
bool isPrime(int x) {
    int end = (int)sqrt(x);
    for(int i = 2; i <= end; i++) {
        if(x % i) return false;
    }
    return true;
}
int main(void) {
    cin >> m >> n;
    for(int i = 2; i <= n; i++) {
        a[i] = i;
    }
    for(int i = 2; i <= n; i++) {
        if(a[i] == 0) continue;
        for(int j = i + i; j <= n; j += i) {
            a[j] = 0;
        }
    }
    for(int i = m; i <= n; i++) {
        if(a[i]) {
            sum += a[i];
            minp = min(minp, a[i]);
        }
    }
    if(sum == 0) cout << -1;
    else cout << sum << '\n' << minp;
    return 0;
}
