//
//  temp.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/18.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//void quickSort(int a[], int start, int end) {
//    if(start >= end)
//        return;
//
//    int key = start;
//    int i = start + 1;
//    int j = end;
//    int temp;
//
//    while(i <= j) {
//        while(a[i] <= a[key] && i <= end)
//            i++;
//        while (a[j] >= a[key] && j > start)
//            j++;
//
//        if(i > j) {
//            temp = a[j];
//            a[j] = a[key];
//            a[key] = temp;
//        } else {
//            temp = a[i];
//            a[i] = a[j];
//            a[j] = temp;
//        }
//    }
//
//    quickSort(a, start, j - 1);
//    quickSort(a, j + 1, end);
//}
//
//
//int main() {
//
//    return 0;
//}
#include <string>
#include <vector>
#include <iostream>
// #include <algorithm>

using namespace std;

void quickSort(vector<int> & citations, int start, int end) {
    if(start >= end) return;
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;
    
    while(i <= j) {
        while(citations[key] <= citations[i] && i <= end)
            i++;
        while(citations[key] >= citations[j] && j > start)
            j--;
        if(i > j) {
            temp = citations[j];
            citations[j] = citations[key];
            citations[key] = temp;
        } else {
            temp = citations[i];
            citations[i] = citations[j];
            citations[j] = temp;
        }
    }
    
    quickSort(citations, start, j - 1);
    quickSort(citations, j + 1, end);
}

int solution(vector<int> citations) {
    int answer = 0;
    quickSort(citations, 0, citations.size() - 1);
    
    for(int i = 0; i < citations.size(); i++) {
        if(citations[i] == 0) return 0;
//        if(citations[i] <= citations.size() - i && citations[i] >= i) answer = citations[i];
        if(citations[i] > i) answer++;
        else break;
        
    }
    
    return answer;
}
int main(void) {
    
    vector<int> a = {4, 0, 6, 1, 5, 4, 6, 7, 8, 9, 10, 5, 5};
    cout << solution(a);
    
    return 0;
}
