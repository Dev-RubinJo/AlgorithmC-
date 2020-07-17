//
//  temp.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/18.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void quickSort(int a[], int start, int end) {
    if(start >= end)
        return;
    
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;
    
    while(i <= j) {
        while(a[i] <= a[key] && i <= end)
            i++;
        while (a[j] >= a[key] && j > start)
            j++;
        
        if(i > j) {
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
    
    return 0;
}
