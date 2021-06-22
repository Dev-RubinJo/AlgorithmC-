//
//  7453.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/07.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[4001][4], idx;
ll f[16000001], b[16000001];
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 4; j++)
            cin >> a[i][j];
    idx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            f[idx] = a[i][0] + a[j][1];
            b[idx] = a[i][2] + a[j][3];
            idx += 1;
        }
    }
    sort(f, f + idx);
    sort(b, b + idx);
    ll l = 0, r = idx - 1;
    int res = 0;
    while(l < idx && r >= 0) {
        ll temp = f[l] + b[r];
        if(temp < 0) l += 1;
        else if(temp > 0) r -= 1;
        else {
            ll lOrig = l;
            ll samel = 0, samer = 0;
            while(f[l] + b[r] == 0) {
                if(l >= idx) break;
                samel += 1;
                l += 1;
            }
            while(f[lOrig] + b[r] == 0) {
                if(r < 0) break;
                samer += 1;
                r -= 1;
            }
            res += samel * samer;
        }
    }
    cout << res;
    return 0;
}
