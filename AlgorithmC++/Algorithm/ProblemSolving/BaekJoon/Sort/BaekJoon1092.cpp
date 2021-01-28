//
//  BaekJoon1092.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/24.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void quickSort(int a[], int start, int end) {
    if(start >= end) return;
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;
    
    while(i <= j) {
        while(a[i] >= a[key] && i <= end)
            i++;
        while(a[j] <= a[key] && j > start)
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
    int n, numOfBox;
    int crane[50] = {0, }, craneMax = 0;
    int box[10000] = {0, }, boxMax = 0;
    
    int count = 0;
    int boxIndex = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> crane[i];
        if(craneMax < crane[i]) craneMax = crane[i];
    }
    
    cin >> numOfBox;
    for(int i = 0; i < numOfBox; i++) {
        cin >> box[i];
        if(boxMax < box[i]) boxMax = box[i];
    }
    
    if(boxMax > craneMax) {
        cout << -1;
        return 0;
    }
//    sort(crane, crane + n);
//    sort(box, box + numOfBox);
    quickSort(crane, 0, n - 1);
    quickSort(box, 0, numOfBox - 1);
    
    while(true) {
        count += 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = boxIndex; j < numOfBox; j++) {
                if(box[j] <= crane[i] && box[j] != 0) {
                    if(boxIndex < j) {
                        int temp = box[boxIndex];
                        box[boxIndex] = box[j];
                        box[j] = temp;
                        box[boxIndex] = 0;
                        boxIndex += 1;
                        break;
                    }
                    boxIndex += 1;
                    box[j] = 0;
                    break;
                }
            }
        }
        if(boxIndex == numOfBox)
            break;
    }
    
    cout << count;
    
    return 0;
}


/*
 #include <iostream>
 #include <algorithm>
 #include <vector>
 using namespace std;



 bool cmp(int a, int b) {
     if (a > b)return true;
     return false;
 }

 int main() {
 
     int crane[51] = { 0 };
     vector <int> box;
     int n = 0, m = 0, result = 0;
 
     cin >> n;
     for (int i = 0; i < n; i++)
         cin >> crane[i];
     cin >> m;
     int num = 0;
     for (int i = 0; i < m; i++) {
         cin >> num;
         box.push_back(num);
     }

     sort(crane, crane + n, cmp);
     sort(box.begin(), box.end(), cmp);

     if (crane[0] < box[0]) {
         cout << -1 << endl;
         return 0;
     }

     
     while (1) {
         result++;

         for (int i = 0; i < n; i++) {
             
             for (int j = 0; j < box.size(); j++) {
                 if (crane[i] >= box[j]) {
                     box.erase(box.begin() + j);
                     break;
                 }
             }
         }
     
         if (box.size() == 0)
             break;
         
     }
     cout << result << '\n';

 }
 */
