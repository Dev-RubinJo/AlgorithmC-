//
//  1992-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/01.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int orin;
char a[65][65];
void dfs(int x, int y, int n) {
    if(n == 1) {
        cout << a[y][x];
        return;
    }
    char b = a[y][x];
    int flag = 0;
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            if(b != a[i][j]) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    
    if(flag) {
        cout << "(";
        dfs(x, y, n / 2);
        dfs(x + n / 2, y, n / 2);
        dfs(x, y + n / 2, n / 2);
        dfs(x + n / 2, y + n / 2, n / 2);
        cout << ")";
    } else {
        cout << b;
        return;
    }
}
int main(void) {
    cin >> orin;
    for(int i = 0; i < orin; i++) {
        for(int j = 0; j < orin; j++) {
            cin >> a[i][j];
        }
    }
    dfs(0, 0, orin);
    return 0;
}
