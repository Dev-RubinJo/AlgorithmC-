//
//  test.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/30.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, res;
int main(void) {
    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        string s = to_string(i);
        if(s[s.size() - 1] != '3' && s[s.size() - 1] != '6' && s[s.size() - 1] != '9')
            continue;
        else res += 1;
    }
    cout << res;
    return 0;
}
