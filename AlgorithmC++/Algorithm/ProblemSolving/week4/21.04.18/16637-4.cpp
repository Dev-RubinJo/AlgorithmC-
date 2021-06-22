//
//  16637-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/18.
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
void input() {
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9) nums.push_back(s[i] - '0');
        else oper.push_back(s[i]);
    }
}
int calculate(int a, int b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    else return a * b;
}
void func(int idx, int num) {
    if(idx == oper.size()) {
        ans = max(ans, num);
        return;
    }
    func(idx + 1, calculate(num, nums[idx + 1], oper[idx]));
    if(idx + 2 <= oper.size()) {
        int temp = calculate(nums[idx + 1], nums[idx + 2], oper[idx + 1]);
        func(idx + 2, calculate(num, temp, oper[idx]));
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func(0, nums[0]);
    cout << ans;
    return 0;
}
