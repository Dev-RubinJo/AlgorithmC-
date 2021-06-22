//
//  1940-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/28.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
int arrays[15001];
int main(void) {
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++) {
        cin >> arrays[i];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arrays[i] + arrays[j] == m && arrays[i] != 0 && arrays[j] != 0) {
                cnt += 1;
                arrays[i] = arrays[j] = 0;
            }
        }
    }
    cout << cnt;
    return 0;
}
