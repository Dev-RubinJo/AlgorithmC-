//
//  12869-f1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/10.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, scv[3], a[3] = {9, 3, 1}, total, temp, ans;

void solution();
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> scv[i];
        total += scv[i];
        temp += a[i];
    }
    if (total / temp != 0) {
        if (total % temp) {
            ans = total / temp + 1;
        } else {
            ans = total / temp;
        }
    } else {
        ans = 1;
    }
    
    cout << ans;

    return 0;
}
// TODO: 틀림
