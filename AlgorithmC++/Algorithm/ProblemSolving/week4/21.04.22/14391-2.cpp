//
//  14391-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, m, ans, a[4][4];
string s;
void func() {
    for(int k = 0; k < (1 << n * m); k++) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int cur = 0;
            for(int j = 0; j < m; j++) {
                int s = i * m + j;
                if(!(k & (1 << s))) cur = cur * 10 + a[i][j];
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        for(int j = 0; j < m; j++) {
            int cur = 0;
            for(int i = 0; i < n; i++) {
                int s = i * m + j;
                if(k & (1 << s)) cur = cur * 10 + a[i][j];
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ans = max(ans, sum);
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++)
            a[i][j] = s[j] - '0';
    }
    func();
    cout << ans;
    return 0;
}
