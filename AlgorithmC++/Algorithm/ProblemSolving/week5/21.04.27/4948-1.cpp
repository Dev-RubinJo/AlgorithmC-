//
//  4948-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/27.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans;
bool v[246913];
void check() {
    for(ll i = 2; i <= 2 * 123456; i++)
        v[i] = 1;
    for(ll i = 2; i <= 2 * 123456; i++) {
        if(!v[i]) continue;
        for(ll j = i * i; j <= 2  * 123456; j += i)
            v[j] = 0;
    }
}
int main(void) {
    check();
    while(1) {
        cin >> n;
        if(!n) break;
        ans = 0;
        for(int i = n + 1; i <= 2 * n; i++)
            if(v[i])
                ans += 1;
        cout << ans << '\n';
    }
    return 0;
}
