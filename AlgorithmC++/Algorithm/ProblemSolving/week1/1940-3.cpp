//
//  1940-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/30.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, res;
int arr[15001];
int main(void) {
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    while(i < j) {
        if(arr[i] + arr[j] == m) { res += 1; i += 1; j -= 1; }
        else if(arr[i] + arr[j] < m) i += 1;
        else j -= 1;
    }
    cout << res;
    return 0;
}
