//
//  1992-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/02.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
char a[65][65];
string dfs(int y, int x, int n) {
    if(n == 1) return string(1, a[y][x]); // MARK: dfs의 끝나는 조건을 잘 명시해야한다.
    int flag = 0;
    char b = a[y][x];
    for(int i = y; i < y + n; i++) { // MARK: y, x두개를 어느 방향으로 먼저 돌릴지 기준삼아서 for문을 돌리는 dfs를 하는게 핵심
        for(int j = x; j < x + n; j++) {
            if (b != a[i][j]) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    if (flag) { // MARK: 왼위, 오위, 왼아, 오아에 따라 dfs를 또 돌리는 것을 중요하게 생각해야한다.
        string lu = dfs(y, x, n / 2);
        string ru = dfs(y, x + n / 2, n / 2);
        string ld = dfs(y + n / 2, x, n / 2);
        string rd = dfs(y + n / 2, x + n / 2, n / 2);
        return ("(" + lu + ru + ld + rd + ")");
    }
    return string(1, b);
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    cout << dfs(0, 0, n);
    return 0;
}
