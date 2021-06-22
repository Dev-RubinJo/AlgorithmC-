//
//  1182.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/07.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, s, res;
int a[41];
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int k = 1; k <= n; k++) {
        int c[41] = {0, };
        for(int i = 0; i < k; i++) c[i] = 1;
        sort(c, c + n);
        do {
            int temp = 0;
            for(int i = 0; i < n; i++) if(c[i]) temp += a[i];
            if(temp == s) res += 1;
        } while(next_permutation(c, c + n));
    }
    cout << res;
    return 0;
}
