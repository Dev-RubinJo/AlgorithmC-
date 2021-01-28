//
//  BaekJoon2774.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/19.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string a;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp[11] = {0, };
        int ans = 0;
        cin >> a;
        for(int j = 0; j < a.size(); j++) {
            temp[a[j] - '0'] += 1;
        }
        for(int j = 0; j < 10; j++) {
            if(temp[j] > 0) {
                ans += 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
