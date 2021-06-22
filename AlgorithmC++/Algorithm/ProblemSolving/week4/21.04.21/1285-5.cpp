//
//  1285-5.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/21.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, a[21], ans = INT_MAX;
string s;
void func(int idx) {
    if(idx == n) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(a[j] & (1 << i)) cnt += 1;
            }
            sum += min(cnt, n - cnt);
        }
        ans = min(ans, sum);
        return;
    }
    a[idx] = ~a[idx];
    func(idx + 1);
    a[idx] = ~a[idx];
    func(idx + 1);
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++)
            if(s[j] == 'T') a[i] |= (1 << j);
    }
    func(0);
    cout << ans;
    return 0;
}
