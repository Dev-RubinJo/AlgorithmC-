//
//  14890-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, l, a[101][101], ans;
void input() {
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}
void func() {
    for(int i = 0; i < n; i++) {
        int cnt = 1;
        int j;
        for(j = 1; j < n; j++) {
            if(a[i][j - 1] == a[i][j] - 1 && cnt >= l) cnt = 1;
            else if(a[i][j - 1] == a[i][j] + 1 && cnt >= 0) cnt = -l + 1;
            else if(a[i][j - 1] == a[i][j]) cnt += 1;
            else break;
        }
        if(j == n && cnt >= 0) ans += 1;
        cnt = 1;
        for(j = 1; j < n; j++) {
            if(a[j - 1][i] == a[j][i] - 1 && cnt >= l) cnt = 1;
            else if(a[j - 1][i] == a[j][i] + 1 && cnt >= 0) cnt = -l + 1;
            else if(a[j - 1][i] == a[j][i]) cnt += 1;
            else break;
        }
        if(j == n && cnt >= 0) ans += 1;
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func();
    cout << ans;
    return 0;
}
