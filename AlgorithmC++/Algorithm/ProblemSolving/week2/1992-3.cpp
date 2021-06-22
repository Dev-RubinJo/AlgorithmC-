//
//  1992-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/03.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
char a[65][65];
int n;
string dfs(int y, int x, int n) {
    if(n == 1) return string(1, a[y][x]);
    char b = a[y][x]; int flag = 0;
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            if(b != a[i][j]) {
                flag = 1;
                break;
            }
        }
    }
    if(flag) {
        string lu = dfs(y, x, n / 2);
        string ru = dfs(y, x + n / 2, n / 2);
        string ld = dfs(y + n / 2, x, n / 2);
        string rd = dfs(y + n / 2, x + n / 2, n / 2);
        return "(" + lu + ru + ld + rd + ")";
    }
    return string(1, b);
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << dfs(0, 0, n);
}
