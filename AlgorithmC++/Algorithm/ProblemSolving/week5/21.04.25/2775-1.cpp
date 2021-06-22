//
//  2775-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int tc, k, n;
int apart[15][15];
int main(void) {
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        fill(&apart[0][0], &apart[0][0] + 14 * 14, 0);
        cin >> k >> n;
        for(int i = 0; i < n; i++) {
            apart[0][i] = i + 1;
        }
        for(int i = 1; i <= k; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0) {
                    apart[i][j] = 1;
                } else {
                    apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
                }
            }
        }
        cout << apart[k][n - 1] << '\n';
    }
    return 0;
}
