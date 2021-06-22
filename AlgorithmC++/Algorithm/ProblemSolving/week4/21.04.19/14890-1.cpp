//
//  14890-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/19.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, l, a[101][101], ans;
void input() {
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
}
void func() {
    for(int i = 0; i < n; i++) {
        int cnt = 1, j = 0;
        for(j = 0; j < n - 1; j++) {
            if(a[i][j] == a[i][j + 1]) cnt += 1;
            else if(a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;
            else if(a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1;
            else break;
        }
        if(j == n - 1 && cnt >= 0) ans += 1;
        cnt = 1;
        for(j = 0; j < n - 1; j++) {
            if(a[j][i] == a[j + 1][i]) cnt += 1;
            else if(a[j][i] + 1 == a[j + 1][i] && cnt >= l) cnt = 1;
            else if(a[j][i] - 1 == a[j + 1][i] && cnt >= 0) cnt = -l + 1;
            else break;
        }
        if(j == n - 1 && cnt >= 0) ans += 1;
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func();
    cout << ans;
    return 0;
}
/*
 void func() {
     for(int i = 0; i < n; i++) {
         int cnt = 0, start = a[i][0], lower = 0, flag = 0;
         for(int j = 0; j < n; j++) {
             if(a[i][j] == start + 1) {
                 start = a[i][j];
                 if(cnt >= l)
                     cnt = 1;
                 else {
                     flag = 1;
                     break;
                 }
             } else if(a[i][j] == start - 1) {
                 lower = start;
                 start = a[i][j];
                 cnt = 1;
             } else if(start == a[i][j]) {
                 cnt += 1;
                 if(lower) {
                     if(cnt >= l) {
                         lower = 0;
                     }
                 }
             } else {
                 flag = 1;
                 break;
             }
         }
         
         if(!flag && !lower) ans += 1;
         cnt = 0; start = a[0][i]; lower = 0; flag = 0;
         for(int j = 0; j < n; j++) {
             if(a[j][i] == start + 1) {
                 start = a[j][i];
                 if(cnt >= l)
                     cnt = 1;
                 else {
                     flag = 1;
                     break;
                 }
             } else if(a[j][i] == start - 1) {
                 lower = start;
                 start = a[j][i];
                 cnt = 1;
             } else if(start == a[j][i]) {
                 cnt += 1;
                 if(lower) {
                     if(cnt >= l) {
                         lower = 0;
                     }
                 }
             } else {
                 flag = 1;
                 break;
             }
         }
         
         if(!flag && !lower) ans += 1;
     }
 }
 */
