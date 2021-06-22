/*
이 문제는 dp로 풀어야할것 같다는 생각이 몹시 크게 든다.

*/

#include <bits/stdc++.h>
using namespace std;
int r, c, t;
int dp[101][101][11];
string m1[101];
int gy, gx;

void input() {
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++) {
        cin >> m1[i];
        for(int j = 0; j < c; j++) {
            if(m1[i][j] == 'G') {
                gy = i; gx = j;
            }
        }
    }
}

int func(int y, int x, int ti) {

}