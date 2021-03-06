//
//  15652-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/08.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
int n, m, a[8];
void func(int k) {
    if(k == m) {
        for(int i = 1; i < m; i++) if(a[i - 1] > a[i]) return;
        for(int i = 0; i < m; i++) cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!a[k]) {
            a[k] = i;
            func(k + 1);
            a[k] = 0;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    func(0);
    return 0;
}
