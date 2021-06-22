//
//  14391-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/20.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, m, a[4][4], res;
bool visited[4][4];
void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++)
            a[i][j] = s[j] - '0';
    }
}
void func() {
    for (int s = 0; s < (1 << (n * m)); s++) {
        int sum = 0;
        for (int i = 0; i < n; i++) { // 가로로 쪼개기
            int cur = 0;
            for (int j = 0; j < m; j++) {
                int k = i * m + j;
                if (!(s & (1 << k))) {
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        for (int j = 0; j < m; j++) { // 세로로 쪼개기
            int cur = 0;
            for (int i = 0; i < n; i++) {
                int k = i * m + j;
                if (s & (1 << k)) {
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        res = max(res, sum);
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func();
    cout << res;
    return 0;
}
