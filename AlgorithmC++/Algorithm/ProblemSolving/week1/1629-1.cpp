//
//  1629-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/28.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;

ll multi(ll a, ll b) {
    if(b == 1)
        return a % c;
    else {
        ll temp = multi(a, b / 2);
        if(b % 2 == 0)
            return (temp * temp) % c;
        else
            return ((temp * temp) % c) * a % c;
    }
}

int main(void) {
    cin >> a >> b >> c;
    cout << multi(a, b);
    return 0;
}
