//
//  nt3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int arr[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[51];
int solution(int k) {
    int answer = 0;
    dp[0] = dp[1] = 0;
    dp[2] = dp[3] = 1;
    dp[4] = 2; dp[5] = 5;
    for(int i = 6; i <= k; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    answer = dp[k];
    return answer;
}
int main(void) {
//    cout << solution(5) << '\n';
//    cout << solution(6) << '\n';
    cout << solution(11) << '\n';
//    cout << solution(1) << '\n';
    return 0;
}
