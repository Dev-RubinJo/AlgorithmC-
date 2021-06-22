//
//  11729-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> v;
void func(int num, int f, int t, int m) {
    if(num == 1) {
        v.push_back({f, t});
        return;
    }
    func(num - 1, f, m, t);
    v.push_back({f, t});
    func(num - 1, m, t, f);
}
int main(void) {
    cin >> n;
    func(n, 1, 3, 2);
    cout << v.size() << '\n';
    for(auto a: v) {
        cout << a.first << " " << a.second << '\n';
    }
    return 0;
}
