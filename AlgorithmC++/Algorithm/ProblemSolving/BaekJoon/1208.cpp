//
//  1208.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/07.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, s, res;
int a[41];
vector<int> f, b;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int k = 1; k < n / 2; k++) {
        int c[21] = {0, };
        for(int i = 0; i < k; i++) c[i] = 1;
        sort(c, c + n);
        do {
            int temp = 0;
            for(int i = 0; i < n / 2; i++) if(c[i]) temp += a[i];
            f.push_back(temp);
        } while(next_permutation(c, c + n));
    }
    for(int k = 1; k < n / 2; k++) {
        int c[21] = {0, };
        for(int i = 0; i < k; i++) c[i] = 1;
        sort(c, c + n);
        do {
            int temp = 0;
            for(int i = n / 2; i <= n; i++) if(c[i - n / 2]) temp += a[i];
            b.push_back(temp);
        } while(next_permutation(c, c + n));
    }
    sort(f.begin(), f.end());
    sort(b.begin(), b.end());
    int l = 0, r = idx - 1;
    while(l < idx && r >= 0) {
        if(f[l] + b[r] == s) {
            int lorig = l;
            int samel = 0, samer = 0;
            while(f[l] + b[r] == s) {
                if(l >= idx) break;
                samel += 1;
                l += 1;
            }
            while(f[lorig] + b[r] == s) {
                if(r < 0) break;
                samer += 1;
                r -= 1;
            }
            res += samel * samer;
        } else if (f[l] +  b[r] < s) {
            l += 1;
        } else {
            r -= 1;
        }
    }
    cout << res;
    return 0;
}
