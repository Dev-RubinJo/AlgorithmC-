//
//  BaekJoon10989.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/12.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, temp;
    int a[10000] = {0, };
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> temp;
        a[temp - 1]++;
    }
    
    for(int i = 0; i < 10000; i++) {
        for(int j = 0; j < a[i]; j++) {
            //cout << i + 1 << endl; // endl은 속도가 느리다. "\n"으로 쓸것
            cout << i + 1 << "\n";
        }
    }
    
    return 0;
}

// 이 문제 어느정도 난이도 있는 문제로 괜찮은듯
// 계수정렬을 공부하고 나서 풀면 좋은 문제
