//
//  16637-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/15.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, ans = INT_MIN;
string s;
vector<int> nums;
vector<char> oper;
int calculate(int a, int b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    return a * b;
}
void go(int x, int num) {
    if(x == nums.size() - 1) {
        ans = max(res, num);
        return;
    }
    go(x + 1, calculate(num, nums[x + 1], oper[x]));
    if(x + 2 <= nums.size() - 1) {
        int temp = calculate(nums[x + 1], nums[x + 2], oper[x + 1]);
        go(x + 2, calculate(num, temp, oper[x]));
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
    go(0, num[0]);
    cout << ans;
    return 0;
}
