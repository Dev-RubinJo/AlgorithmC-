//
//  14729-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/23.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
priority_queue<double> pq;
vector<double> v;
int main(void) {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        double a; scanf("%lf", &a);
        if(pq.size() == 7) {
            pq.push(a); pq.pop();
        } else {
            pq.push(a);
        }
    }
    
    while(!pq.empty()) {
        v.push_back(pq.top()); pq.pop();
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < 7; i++) {
        printf("%0.3f\n", v[i]);
    }
    return 0;
}
