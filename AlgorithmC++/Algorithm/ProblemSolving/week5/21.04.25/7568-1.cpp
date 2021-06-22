//
//  7568-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/25.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, t1, t2;
pair<int, int> a[51];
map<int, int> m1;
bool check(pair<int, int> a, pair<int, int> b) {
    if(a.first < b.first && a.second < b.second) return false;
    return true;
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        a[i] = {t1, t2};
        m1[i] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(check(a[i], a[j]) && m1[i] == 1) m1[i] = 1;
            else if(check(a[i], a[j])) continue;
            else m1[i] += 1;
        }
    }
    for(auto it: m1) cout << it.second << " ";
    return 0;
}
