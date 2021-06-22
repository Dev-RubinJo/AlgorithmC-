//
//  1629-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/30.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;
ll multi(ll b) {
    if(b == 1)
        return a % c;
    else {
        ll temp = multi(b / 2);
        temp = (temp * temp) % c;
        if(b % 2)
            temp = (temp * a) % c;
        return temp;
    }
}
int main(void) {
    cin >> a >> b >> c;
    cout << multi(b);
    return 0;
}
