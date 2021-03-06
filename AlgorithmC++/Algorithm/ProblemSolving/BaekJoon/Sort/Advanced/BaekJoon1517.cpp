//
//  BaekJoon1517.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/12.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//
// 어려움

#include <stdio.h>
#include <iostream>

using namespace std;

int n;
long long ans = 0;
int v[500000], tmp[500000];

void merge(int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;
    int cnt = 0;
    
    while(i <= middle && j <= n) {
        if(v[i] <= v[j])
            tmp[k++] = v[i++];
        else {
            tmp[k++] = v[j++];
            ans += middle + 1 - i;
        }
    }
    while(i <= middle)
        tmp[k++] = v[i++];
    while(j <= n)
        tmp[k++] = v[j++];
    
    for(i = m; i <= n; i++)
        v[i] = tmp[i];
}

void mergeSort(int m, int n) {
    int middle;
    if(m < n) {
        middle = (m + n) / 2;
        mergeSort(m, middle);
        mergeSort(middle + 1, n);
        merge(m, middle, n);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    mergeSort(0, n - 1);
    cout << ans;
}
