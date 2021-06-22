//
//  smart.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/30.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, k, res, flag;
char a[20001];
int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        flag = 0;
        if(a[i] == 'P') {
            if(i == 0) {
                for(int j = 1; j < k; j++) {
                    if(a[j] == 'H') {
                        res += 1;
                        a[j] = 'a';
                        break;
                    }
                }
            } else {
                for(int j = i - k; j < i; j++) {
                    if(a[j] == 'H') {
                        res += 1;
                        a[j] = 'a';
                        flag = 1;
                        break;
                    }
                }
                if(!flag) {
                    for(int j = i + 1; j < k + i + 1; j++) {
                        if(a[j] == 'H') {
                            res += 1;
                            a[j] = 'a';
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}
