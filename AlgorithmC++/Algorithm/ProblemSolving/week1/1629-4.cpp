//
//  1629-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;
ll multi(ll b) {
    if(b == 1) return a % c;
    ll temp = multi(b / 2);
    temp = temp * temp % c;
    if(b % 2) temp = temp * a % c;
    return temp;
}
int main(void) {
    cin >> a >> b >> c;
    cout << multi(b);
    return 0;
}
