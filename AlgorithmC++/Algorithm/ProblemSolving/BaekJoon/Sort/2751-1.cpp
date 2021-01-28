//
//  2751-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/01/13.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <iostream>

using namespace std;

void merge(int arr[], int sorted[], int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;
    
    while (i <= middle && j <= n) {
        if (arr[i] < arr[j]) {
            sorted[k] = arr[i];
            i += 1;
        } else {
            sorted[k] = arr[j];
            j += 1;
        }
        k += 1;
    }
    
    if (i > middle) {
        for (int l = j; l <= n; l++) {
            sorted[k] = arr[l];
            k += 1;
        }
    } else {
        for (int l = i; l <= middle; l++) {
            sorted[k] = arr[l];
            k += 1;
        }
    }
    
    for (int l = m; l <= n; l++) {
        arr[l] = sorted[l];
    }
}

void mergeSort(int arr[], int sorted[], int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(arr, sorted, m, middle);
        mergeSort(arr, sorted, middle + 1, n);
        merge(arr, sorted, m, middle, n);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[1000001] = {0, };
    int sorted[1000001] = {0, };
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    mergeSort(arr, sorted, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    
    return 0;
}
