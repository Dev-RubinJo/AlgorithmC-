//
//  3273-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/27.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, a[100002], f, l, t, ans;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> t;
    sort(a, a + n);ㅠ
    f = 0;
    l = n - 1;
    while(f < l) {
        if(a[f] + a[l] > t) l -= 1;
        else if(a[f] + a[l] < t) f += 1;
        else if(a[f] + a[l] == t) {
            ans += 1;
            l -= 1;
            f += 1;
        }
    }
    cout << ans;
    return 0;
}
