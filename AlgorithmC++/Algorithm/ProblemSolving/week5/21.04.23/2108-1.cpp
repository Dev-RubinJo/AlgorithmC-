//
//  2108-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/23.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, a[8004], sum, minv = 4001, maxv = -4001, lots, idx;
vector<int> v;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        a[temp + 4000] += 1;
        v.push_back(temp);
        sum += temp;
        maxv = max(maxv, temp);
        minv = min(minv, temp);
    }
    for(int i = minv; i < maxv + 1; i++) {
        if(lots < a[i + 4000]) {
            lots = a[i + 4000];
            idx = i;
            cnt = 1;
        } else if(lots == a[i + 4000] && cnt == 1) {
            cnt += 1;
            idx = i;
        }
    }
    sort(v.begin(), v.end());
    cout << round((double)sum / (double)n) << endl;
    cout << v[n / 2] << endl;
    cout << idx << endl;
    cout << maxv - minv;

    return 0;
}
