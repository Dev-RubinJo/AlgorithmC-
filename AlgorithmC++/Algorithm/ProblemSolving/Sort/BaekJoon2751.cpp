//
//  BaekJoon2751.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/10.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//


#include <stdio.h>
#include <iostream>
/*
void quickSort(int *a, int start, int end) {
    if(start >= end) {
        return;
    }
    
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;
    
    while(i <= j) {
        while(a[i] <= a[key] && i <= end)
            i++;
        while(a[j] >= a[key] && j > start)
            j--;
        
        if (i > j) {
            temp = a[j];
            a[j] = a[key];
            a[key] = temp;
        } else {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    
    quickSort(a, start, j - 1);
    quickSort(a, j + 1, end);
}

// MARK:  퀵정렬을 이용하여 풀었다. 하지만 퀵정렬은 최악의 경우에 O(N^2)시간이 걸리기에 틀린것 같다.
//update, 퀵정렬때문에 틀린게 아니라 cout 때문에 틀림

 int main() {
     
     int a[1000000] = {0, };
     int n;
     scanf("%d", &n);
     for(int i = 0; i < n; i++) {
         scanf("%d", &a[i]);
     }
     
     quickSort(a, 0, n - 1);
     
     for(int i = 0; i < n; i++) {
         std::cout << a[i] << std::endl;
     }
     
     return 0;
 }
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int a[1000000];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    std::sort(a, a + n);
    
    for(int i = 0; i < n; i++) {
        std::cout << a[i] << std::endl; // <- 시간초과 원인
    }
    
    return 0;
}
