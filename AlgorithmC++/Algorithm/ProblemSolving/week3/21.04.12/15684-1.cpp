//
//  15684-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/12.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, m, h, m1[31][11], a, b;
bool check() {
    for(int i = 0; i < n; i++) {
        int r = 0, c = i;
        do {
            if(m1[r][c] == 2)
                c -= 1;
            else if(m1[r][c] == 1)
                c += 1;
            r += 1;
        } while(r != h);
        if(c != i) return 0;
    }
    return 1;
}
int solve(int pos, int cnt) {
    if(cnt == 3 || pos >= n * h) {
        if(check()) return cnt;
        return 987654321;
    }
    int res = 987654321;
    int r = pos / n, c = pos % n;
    if(c != n - 1 && !m1[r][c] && !m1[r][c + 1]) {
        m1[r][c] = 1;
        m1[r][c + 1] = 2;
        res = min(res, solve(pos + 2, cnt + 1));
        m1[r][c] = m1[r][c + 1] = 0;
    }
    res = min(res, solve(pos + 1, cnt));
    return res;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        m1[a - 1][b - 1] = 1;
        m1[a - 1][b] = 2;
    }
    int res = solve(0, 0);
    cout << ((res == 987654321) ? -1 : res);
    return 0;
}
