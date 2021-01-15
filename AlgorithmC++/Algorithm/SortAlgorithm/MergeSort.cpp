//
//  MergeSort.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/11.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void merge(int a[], int sorted[], int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;
    
    while(i <= middle && j <= n) {
        if(a[i] < a[j]) {
            sorted[k] = a[i];
            i++;
        } else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    
    if(i > middle) {
        for(int l = j; l <= n; l++) {
            sorted[k] = a[l];
            k++;
        }
    } else {
        for(int l = i; l <= middle; l++) {
            sorted[k] = a[l];
            k++;
        }
    }
    for(int l = m; l <= n; l++) {
        a[l] = sorted[l];
    }
}

void mergeSort(int a[], int sorted[], int m, int n) {
    if(m < n) {
        int middle = (m + n) / 2;
        mergeSort(a, sorted, m, middle);
        mergeSort(a, sorted, middle + 1, n);
        merge(a, sorted, m, middle, n);
    }
}

int main() {
    int a[10] = {7, 6, 5, 8, 3, 5, 9, 1, 4, 2};
    int sorted[10] = {0, };
    
    mergeSort(a, sorted, 0, 9);
    for(int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }
    
    return 0;
}
// MARK: - 병합정렬 설명
/*
 
 병합정렬은 퀵정렬과 다르게 최악의 경우에 O(NlogN)의 시간을 가진다
 퀵정렬과 비슷하게 분할정복 방법을 채택함
 
 일단 반으로 쪼개고 나중에 합친다!
 합치면서 크고 작은것 위치를 변경하는 횟수가 버블정렬을 할때 바꾸는 횟수랑 같다
 
 */
