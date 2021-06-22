//
//  2447-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/23.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n;
void star(int i, int j, int num) {
    if((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        cout << " ";
    } else {
        if(num / 3 == 0) cout << "*";
        else star(i, j, num / 3);
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            star(i, j, n);
        }
        cout << endl;
    }
    return 0;
}
