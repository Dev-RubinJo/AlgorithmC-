//
//  1992-l.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/08.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
int n;
char c[65][65];
string dfs(int x, int y, int n) {
    if(n == 1) return string(1, c[y][x]);
    int flag = 0;
    char a = c[y][x];
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            if(a != c[i][j]) {
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
    } else return string(1, a);
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];
    cout << dfs(0, 0, n);
    return 0;
}
