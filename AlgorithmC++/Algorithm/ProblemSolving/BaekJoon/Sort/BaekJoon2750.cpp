//
//  BaekJoon2750.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/10.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

void quickSort(int a[], int start, int end) {
    if(start >= end) {
        return;
    }
    
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;
    
    while(i <= j) {
        while(a[i] <= a[key] && i <= end) {
            i++;
        }
        while(a[j] >= a[key] && j > start) {
            j--;
        }
        
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

int main() {
    
    int a[1000] = {0, };
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
/*
 
 #include <stdio.h>
 #include <iostream>
 
 int main() {
     
     int a[1000] = {0, };
     int n;
     
     scanf("%d", &n);
     
     for(int i = 0; i < n; i++) {
         scanf("%d", &a[i]);
     }
          
     int index = -1;
     for(int i = 0; i < n; i++) {
         int min = 1001;
         for(int j = i; j < n; j++) {
             if(min > a[j]) {
                 min = a[j];
                 index = j;
             }
         }
         int temp = a[index];
         a[index] = a[i];
         a[i] = temp;
     }
     
     for(int i = 0; i < n; i++) {
         std::cout << a[i] << std::endl;
     }
     
     return 0;
 }

 */


