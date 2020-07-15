//
//  BaekJoon1026.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/12.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
//
//bool compare(int a, int b) {
//    return a > b;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int n, res = 0;
//    int a[50], b[50];
//
//    cin >> n;
//    for(int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    for(int i = 0; i < n; i++) {
//        cin >> b[i];
//    }
//
//    sort(a, a + n, compare);
//
//    sort(b, b + n);
//
//
//    for(int i = 0; i < n; i++) {
//        res += a[i] * b[i];
//    }
//
//    cout << res;
//
//
//    return 0;
//}

// 문제에서는 B를 재배열하면 안된다고 나와있긴 하지만
// 답은 결국 최종으로 나오는 S가 답이기에 우선 재배열을 해서 풀었다.

// MARK: - 아래 풀이가 B 배열 안바꾸고 한거
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, res = 0;
    int a[50] = {-1, }, b[50], a_temp[50];
    int max = -1, index = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a_temp[i];
        a[i] = -1;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a_temp, a_temp + n);
    for(int i = 0; i < n; i++) {
        max = -1;
        for(int j = 0; j < n; j++) {
            if(a[j] != -1) {
                continue;
            }
            if(max < b[j]) {
                max = b[j];
                index = j;
            }
        }
        a[index] = a_temp[i];
    }
    
    for(int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }
    
    cout << res;
    
    
    return 0;
}

