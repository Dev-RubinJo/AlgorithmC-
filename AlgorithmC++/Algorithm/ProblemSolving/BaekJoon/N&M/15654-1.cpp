//
//  15654-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/08.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
int n, m, arr[9], a[9];
bool isUsed[9];
void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << a[i] << ' ';
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!isUsed[i]) {
            a[k] = arr[i];
            isUsed[i] = 1;
            func(k + 1);
            isUsed[i] = 0;
        }
    }
}
int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    func(0);
    return 0;
}
