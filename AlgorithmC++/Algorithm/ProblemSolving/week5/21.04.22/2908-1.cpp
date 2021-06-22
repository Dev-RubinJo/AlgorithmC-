//
//  2908-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
string s1, s2;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    cout << ((s1 > s2) ? s1 : s2);
    return 0;
}
