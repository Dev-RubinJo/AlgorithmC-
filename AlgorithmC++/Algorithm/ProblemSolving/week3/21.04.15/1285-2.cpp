//
//  1285-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/15.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, a[21], res = INT_MAX;
string s;
void go(int x) {
    if(x == n + 1) {
        int sum = 0;
        for(int i = 1; i <= (1 << (n - 1)); i *= 2) {
            int cnt = 0;
            for(int j = 1; j <= n; j++)
                if(a[j] & i)
                    cnt += 1;
            sum += min(cnt, n - cnt);
        }
        res = min(res, sum);
        return;
    }
    a[x] = ~a[x];
    go(x + 1);
    a[x] = ~a[x];
    go(x + 1);
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        int value = 1;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == 'T') a[i] |= value;
            value *= 2;
        }
    }
    go(1);
    cout << res;
    return 0;
}
