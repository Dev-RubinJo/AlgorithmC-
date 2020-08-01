//
//  BaekJoon1940.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/01.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n, m, ans = 0;
    cin >> n >> m;
//    int a[15000];
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
//    sort(a, a + n);
    
    for(int i = 0; i < a.size(); i++) {
        for(int j = a.size() - 1; j > i; j--) {
            if(a[i] + a[j] > m) continue;
            else if(a[i] + a[j] == m) {
                ans += 1;
                a.erase(a.begin() + j);
                a.erase(a.begin() + i);
                i -= 1;
                break;
            } else if(a[i] + a[j] < m) break;
        }
    }
    
    cout << ans;
    
    return 0;
}
