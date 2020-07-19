//
//  BaekJoon10867.cpp
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

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, count = 0, index = 0;
    int a[100000];
    int b[2002] = {0, };

    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(b[temp + 1000] == 0) {
            a[index] = temp;
            index += 1;
            count += 1;
        }
        b[temp + 1000] += 1;
    }

    quickSort(a, 0, count - 1);

    for(int i = 0; i < count; i++) {
        cout << a[i] << " ";
    }    
    cout << endl;

    return 0;
}
