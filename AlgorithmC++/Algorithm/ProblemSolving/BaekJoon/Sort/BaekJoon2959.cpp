//
//  BaekJoon2959.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/19.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

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
        while(a[j] >= a[key] && j > start)
            j--;
        
        if(i > j) {
            temp = a[key];
            a[key] = a[j];
            a[j] = temp;
        } else {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    quickSort(a, start, j - 1);
    quickSort(a, j + 1, end);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[4];
    for(int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    quickSort(a, 0, 3);

    cout << a[0] * a[2];

    cout << endl;
    return 0;
}
