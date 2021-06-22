//
//  mcc1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/15.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(int i = 0; i < absolutes.size(); i++) {
        if(signs[i]) {
            answer += absolutes[i];
        } else {
            answer += -absolutes[i];
        }
    }
    return answer;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution({4,7,12}, {1, 0, 1}) << endl;
    return 0;
}
