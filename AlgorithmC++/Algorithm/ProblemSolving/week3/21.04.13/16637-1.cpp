//
//  16637-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/13.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, res = INT_MIN;
string s;
vector<int> num;
vector<char> oper;
int calculate(char op, int a, int b) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    return a * b;
}
void go(int x, int abc) {
    if(x == num.size() - 1) {
        res = max(res, abc);
        return;
    }
    go(x + 1, calculate(oper[x], abc, num[x + 1]));
    if(x + 2 <= num.size() - 1) {
        int temp = calculate(oper[x + 1], num[x + 1], num[x + 2]);
        go(x + 2, calculate(oper[x], abc, temp));
    }
    return;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(i % 2) oper.push_back(s[i]);
        else num.push_back(s[i] - '0');
    }
    go(0, num[0]);
    cout << res;
    return 0;
}
