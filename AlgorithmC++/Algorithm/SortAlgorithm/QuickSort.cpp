//
//  QuickSort.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/09.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <iostream>

/// - parameters:
/// - start: 정렬을 수행하는 배열의 첫번 째 원소 인덱스
/// - end: 정렬을 수행하는 배열의 마지막 원소 인덱스
void quickSort(int a[], int start, int end) {
    if(start >= end) { // 원소가 1개인 경우
        return;
    }
    int key = start; // 첫 번째 원소
    int i = start + 1;
    int j = end;
    int temp;
    
    while(i <= j) { // 엇갈릴 때까지 반복
        while(a[i] <= a[key] && i <= end) { // 키 값보다 큰 값을 만날 때까지 오른쪽으로 이동
            i++;
        }
        while(a[j] >= a[key] && j > start) { // 키 값보다 작은 값을 만날 때 까지 왼쪽으로 이동
            j--;
        }
        
        if(i > j) { // 현재 엇갈린 상태면
            temp = a[j];
            a[j] = a[key];
            a[key] = temp;
        } else {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    quickSort(a, start, j - 1);
    quickSort(a, j + 1, end);
}

int main(int argc, const char * argv[]) {
    
    int a[10] = {10, 1, 5, 8, 7, 6, 4, 3, 2, 9};
//    int a[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
//    int a[10] = {3, 7, 8, 1, 5, 9, 6, 10, 2, 4};
    
    quickSort(a, 0, 9);
    
    for(int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

// MARK: - 퀵정렬 설명
/*
 시간복잡도는 O(NlogN)
 퀵정렬은 기준값이 있는데 이를 Pivot이라고 한다. 이 pivot값을 기준으로 앞뒤로 나눠서 정렬한다.
 보통 처음에는 제일 앞에 있는 값을 pivot으로 설정(함수 인자에서 Start)
 그 값을 기준으로 오른쪽과 왼쪽으로 이동하는데 왼쪽에서부터 움직이는 것은 pivot보다 큰것, 오른쪽에서부터 움직이는 것은 pivot보다 작은 것을 찾는다. 그리고 서로 swap
 이것을 서로 엇갈릴때까지 반복
 엇갈릴때는 작은 값과 pivot값을 변경
 
 pivot을 기준으로 나눠서 정렬한다는 개념덕분에 전체를 한번에 정렬하는 것보다 시간적으로 효율적이다
 
하지만 항상 O(NlogN)은 아니고 최악의 경우에는 O(N^2)이 나온다
 */
