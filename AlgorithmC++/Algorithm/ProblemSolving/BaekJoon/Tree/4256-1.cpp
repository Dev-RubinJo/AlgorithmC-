//
//  4256-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/16.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int tc, n, temp;
void print(int x, int s, int e, vector<int> &pre, vector<int> &in) {
    for(int i = s; i < e; i++) {
        if(pre[x] == in[i]) {
            print(x + 1, s, i, pre, in);
            print(x + (i - s) + 1, i + 1, e, pre, in);
            cout << pre[x] << " ";
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> n;
        vector<int> pre, in;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            pre.push_back(temp);
        }
        for(int i = 0; i < n; i++) {
            cin >> temp;
            in.push_back(temp);
        }
        print(0, 0, n, pre, in);
        cout << endl;
    }
    return 0;
}
