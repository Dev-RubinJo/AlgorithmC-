//
//  1285-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/11.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n;
int coins[21];
int flip(int *coins, int row) {
    if (row == n) {
        int total = 0;// 각 열의 T개수를 더해 전체 T개수 구하고 반환
        for (int i = 0; i < n; i++) {
            int col_t_cnt = 0;
            for (int j = 0; j < n; j++) {
                if (coins[j] & (1 << i)) {
                    col_t_cnt += 1;
                }
            }
            total += min(col_t_cnt, n - col_t_cnt);// 각 열을 뒤집은 경우, 뒤집지 않은 경우 중에서 더 작은 T값 더하기
        }
        return total;
    }
    int unfliped_t_cnt = flip(coins, row + 1);// row행을 뒤집지 않은 경우
    coins[row] = ~coins[row];// row행을 뒤집은 경우
    int fliped_t_cnt = flip(coins, row + 1);
    return min(unfliped_t_cnt, fliped_t_cnt);// 둘 중 더 작은 T 개수 반환
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for(int j = 0; j < n; j++) {
            if(line[j] == 'T') coins[i] |= (1 << j);
        }
    }
    cout << flip(coins, 0);
    return 0;
}
