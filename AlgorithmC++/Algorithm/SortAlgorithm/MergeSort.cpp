//
//  MergeSort.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/11.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

void merge(int sort[], int a[], int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;
    // 작은 순서대로 배열에 삽입
    while(i <= middle && j <= n) {
        if(a[i] <= a[j]) {
            sort[k] = a[i];
            i++;
        } else {
            sort[k] = a[j];
            j++;
        }
        k++;
    }
    // 남은 데이터도 삽입
    if(i > middle) {
        for(int t = j; t <= n; t++) {
            sort[k] = a[t];
            k++;
        }
    } else {
        for(int t = i; t <= middle; t++) {
            sort[k] = a[t];
            k++;
        }
    }
    // 정렬된 배열 삽입
    for(int t = m; t <= n; t++) {
        a[t] = sort[t];
        std::cout << sort[t] << " ";
    }
    std::cout << std::endl;
}

void mergeSort(int sort[], int a[], int m, int n) {
    // 크기가 1보다 큰 경우
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(sort, a, m, middle);
        mergeSort(sort, a, middle + 1, n);
        merge(sort, a, m, middle, n);
    }
}

int main() {
    
    int a[9] = {7, 6, 5, 8, 3, 5, 9, 1, 2};
    int sorted[9];
    
    mergeSort(sorted, a, 0, 8);
    
    for(int i = 0; i < 9; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

// MARK: - 병합정렬 설명
/*
 
 병합정렬은 퀵정렬과 다르게 최악의 경우에 O(NlogN)의 시간을 가진다
 퀵정렬과 비슷하게 분할정복 방법을 채택함
 
 일단 반으로 쪼개고 나중에 합친다!
 
 */
