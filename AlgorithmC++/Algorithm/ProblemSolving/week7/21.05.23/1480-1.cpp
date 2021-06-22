/*
기본적인 냅색문제인거같은데... 이걸 가방이 찼을 때 넘어가는 것을 어떻게 해야할지 모르겠다.
정말 모르겠어서 결국 답을 봤는데 비트마스킹은 상상도 못했다.
*/

#include <bits/stdc++.h>
using namespace std;
int n, m, c, arr[14], dp[11][1 << 14][21]; // dp 각 차원별 사이즈 의미, 11: 가방의 인덱스, 1 << 14 보석 종류, 21 << 가방의 최대 한도

void input() {
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int func(int idx, int jam, int capa) {
    if(idx == m) return 0;
    int &res = dp[idx][jam][capa];
    if(res) return res;
    res = max(res, func(idx + 1, jam, c));
    for(int i = 0; i < n; i++) {
        bool isBeforeJam = (1 << i) & jam;
        bool isJamCan = (capa - arr[i]) >= 0;
        if(!isBeforeJam && isJamCan) res = max(res, func(idx, jam | (1 << i), capa - arr[i]) + 1);
    }
    return res;
}

int main(void) {
    input();
    cout << func(0, 0, c);
    return 0;
}