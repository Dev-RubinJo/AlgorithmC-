//
//  9020-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/27.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int tc, n, ans1, ans2;
bool a[10002];
void prime() {
    for(int i = 2; i < 10001; i++) {
        a[i] = 1;
    }
    for(int i = 2; i < 10001; i++) {
        if(!a[i]) continue;
        for(int j = i * i; j < 10001; j += i)
            a[j] = 0;
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    prime();
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        int l, r;
        cin >> n;
        l = ans1 = 2; r = ans2 = n;
        while(l <= r) {
            if(!a[l]) { l += 1; continue; }
            if(!a[r]) { r -= 1; continue; }
            if(l + r > n && a[l] && a[r]) r -= 1;
            else if(l + r < n && a[l] && a[r]) l += 1;
            else if(l + r == n && a[l] && a[r]) {
                if(ans2 - ans1 > r - l) {
                    ans1 = l;
                    ans2 = r;
                }
                l += 1;
                r -= 1;
            }
            
        }
        cout << ans1 << " " << ans2 << '\n';
    }
    return 0;
}
