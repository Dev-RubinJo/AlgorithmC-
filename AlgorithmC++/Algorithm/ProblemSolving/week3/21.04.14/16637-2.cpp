//
//  16637-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/14.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, res = INT_MIN;
string s;
vector<char> oper;
vector<int> nums;
int calculate(int a, int b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    return a * b;
}
void go(int idx, int num) {
    if(idx == nums.size() - 1) {
        res = max(res, num);
        return;
    }
    go(idx + 1, calculate(num, nums[idx + 1], oper[idx]));
    if(idx + 2 <= nums.size() - 1) {
        int temp = calculate(nums[idx + 1], nums[idx + 2], oper[idx + 1]);
        go(idx + 2, calculate(num, temp, oper[idx]));
    }
    
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9) nums.push_back(s[i] - '0');
        else oper.push_back(s[i]);
    }
    go(0, nums[0]);
    cout << res;
    return 0;
}
