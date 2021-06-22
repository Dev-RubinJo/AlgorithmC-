//
//  1202-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/23.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
ll n, k, ans, diaIdx, bagIdx;
vector<pair<int, int>> dia;
vector<int> bags;
bool cmpdia(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}
bool cmpbag(int a, int b) {
    return a > b;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        dia.push_back({a, b});
    }
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        bags.push_back(a);
    }
    sort(dia.begin(), dia.end(), cmpdia);
    sort(bags.begin(), bags.end(), cmpbag);
    for(auto a: dia)
        cout << a.first << " " << a.second << endl;
    for(auto a: bags)
        cout << a << endl;
    while(k) {
        if(diaIdx >= dia.size()) break;
        if(dia[diaIdx].first <= bags[bagIdx]) {
            ans += dia[diaIdx].second;
            diaIdx += 1;
            bagIdx += 1;
            k -= 1;
        } else {
            diaIdx += 1 ;
        }
    }
    cout << ans;
    return 0;
}
// MARK: 위 알고리즘은 틀린 알고리즘. 너무 단순하게 생각한게 패인
