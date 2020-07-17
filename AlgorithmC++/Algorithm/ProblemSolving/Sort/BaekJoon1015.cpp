//
//  BaekJoon1015.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/15.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int a[50];
    int p[50];
    
    for(int i = 0; i < 50; i++) {
        p[i] = -1;
    }
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        p[i] = 0;
        for(int j = 0; j < n; j++) {
            if(a[i] > a[j])
                p[i]++;
        }
        
        while(1) {
            bool flag = false;
            
            for(int j = 0; j < n; j++) {
                if(i != j && p[i] == p[j]) {
                    p[i]++;
                    flag = true;
                }
            }
            
            if(flag == false)
                break;
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    
    return 0;
}
// 완전한 오름차순이 아닌 비내림차순임을 명시


//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int n;
//    int a[50];
//    int p[50];
//    int minIndex = 0;
//    int min = 1001;
//
//    for(int i = 0; i < 50; i++) {
//        p[i] = -1;
//    }
//
//    cin >> n;
//    for(int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//
//    for(int i = 0; i < n; i++) {
//        min = 1001;
//        for(int j = 0; j < n; j++) {
//            if(p[j] != -1)
//                continue;
//            if(min  > a[j]) {
//                min = a[j];
//                minIndex = j;
//            }
//        }
//        if(min < 1001) {
//            p[minIndex] = min;
//            i--;
//        }
//    }
//
//    for(int i = 0; i < n; i++) {
//        cout << p[i] - 1 << " ";
//    }
//
//    return 0;
//}
