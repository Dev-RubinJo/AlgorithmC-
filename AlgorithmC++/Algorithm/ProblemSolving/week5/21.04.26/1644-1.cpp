//
//  1644-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans;
bool a[4000002];
ll sum;
void makePrime() {
    for(ll i = 2; i <= n; i++) {
        a[i] = 1;
    }
    for(ll i = 2; i <= n; i++) {
        if(!a[i]) continue;
        for(ll j = i * i; j <= n; j += i) {
            a[j] = 0;
        }
    }
}
int main(void) {
    cin >> n;
    makePrime();
    for(ll i = 1; i <= n; i++) {
        if(!a[i]) continue;
        sum = 0;
        for(ll j = i; j <= n; j++) {
            if(!a[j]) continue;
            sum += j;
            if(sum == n) {
                ans += 1;
                break;
            } else if(sum > n) {
                break;
            }
        }
        
//        cout << i << " ";
    }
    cout << ans;
    return 0;
}
