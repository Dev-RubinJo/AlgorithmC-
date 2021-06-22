//
//  2109-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, ans;
bool d[10002];
priority_queue<int, vector<int>, greater<int>> q; // Greater로 설정하면 오름차순 우선순위 큐가 된다.
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
//        q.push(make_pair(a, b));
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        q.push(v[i].second);
        if(q.size() > v[i].first){
            q.pop();
        }
    }
    while(q.size()){
        ans += q.top(); q.pop();
    }
//    while(!q.empty()) {
//        v.push_back(q.top()); q.pop();
//    }
//    reverse(v.begin(), v.end());
//    while(n > 0) {
//        if(q.top().second > pre) {
//            ans += q.top().first; q.pop();
//        }
//        pre += 1;
//        n -= 1;
//    }
//    for(auto a: v)
//        cout << a.first << " : " << a.second << '\n';

    cout << ans;
    return 0;
}
