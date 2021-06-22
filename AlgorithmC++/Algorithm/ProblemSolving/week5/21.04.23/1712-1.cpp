//
//  1712-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/23.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;
ll t;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    if(b >= c) cout << -1;
    else {
        while(a + (b * t) >= c * t) {
            t += 1;
        }
        cout << t;
    }
    return 0;
}
