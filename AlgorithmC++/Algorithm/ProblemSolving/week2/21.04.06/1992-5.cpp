//
//  1992-5.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
char c[65][65];
int n;
string dfs(int y, int x, int n) {
    if(n == 1) return string(1, c[y][x]);
    char a = c[y][x];
    int flag = 0;
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            if(c[i][j] != a) {
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
    } else return string(1, a);
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    cout << dfs(0, 0, n);
    return 0;
}
