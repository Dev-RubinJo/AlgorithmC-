//
//  3474-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/03.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tc, n, n2, n5;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        cin >> n;
        for(int i = 2; i <= n; i *= 2) n2 += n / i;
        for(int i = 5; i <= n; i *= 5) n5 += n / i;
        cout << min(n2, n5) << '\n';
        n2 = n5 = 0;
    }
    return 0;
}
// MARK:  처음에 문제를 풀기위한 방법을 전혀 생각해내지 못해서 결국 풀이를 보고 함.
// MARK: 소인수 분해를 이용한 수학문제
