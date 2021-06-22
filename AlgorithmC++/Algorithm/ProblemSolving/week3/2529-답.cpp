//
//  2529-답.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/14.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, check[10];
char a[20];
vector<string> res;
bool good(char x, char y, char op) {
    if(x < y && op == '<') return true;
    if(x > y && op == '>') return true;
    return false;
}
void go(int idx, string num) {
    if(idx == n + 1) {
        res.push_back(num);
        return;
    }
    for(int i = 0; i <= 9; i++) {
        if(check[i]) continue;
        if(idx == 0 || good(num[idx - 1], i + '0', a[idx - 1])) {
            check[i] = 1;
            go(idx + 1, num + to_string(i));
            check[i] = 0;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    go(0, "");
    sort(res.begin(), res.end());
    cout << res[res.size() - 1] << endl << res[0];
    return 0;
}
