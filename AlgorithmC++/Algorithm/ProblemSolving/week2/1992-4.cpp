//
//  1992-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
char a[65][65];
string dfs(int x, int y, int n) {
    if(n == 1) return string(1, a[y][x]);
    char b = a[y][x];
    int flag = 0;
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            if(a[i][j] != b) {
                flag = 1;
                break;
            }
        }
    }
    if(flag) {
        string lu = dfs(x, y, n / 2);
        string ru = dfs(x + n / 2, y, n / 2);
        string ld = dfs(x, y + n / 2, n / 2);
        string rd = dfs(x + n / 2, y + n / 2, n / 2);
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
    return 0;
}
