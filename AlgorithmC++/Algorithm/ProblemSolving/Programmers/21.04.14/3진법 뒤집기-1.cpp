//
//  3진법 뒤집기-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/14.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int solution(int n) {
    int answer = 0;
    vector<int> v;
    while(n > 1) {
        v.push_back(n % 3);
        n /= 3;
    }
    if(n) v.push_back(n);
    int j = 0;
    for(int i = v.size() - 1; i >= 0 ; i--) {
//        cout << v[i] << " ";
        answer += v[i] * pow(3, j);
        j += 1;
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution(45) << endl;
    cout << solution(125) << endl;
    return 0;
}
