//
//  BaekJoon1059.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/24.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void quickSort(int lSet[], int start, int end) {
    if(start >= end) return;
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;

    while(i <= j) {
        while(lSet[i] <= lSet[key] && i <= end)
            i++;
        while(lSet[j] >= lSet[key] && j > start)
            j--;
        if(i > j) {
            temp = lSet[j];
            lSet[j] = lSet[key];
            lSet[key] = temp;
        } else {
            temp = lSet[j];
            lSet[j] = lSet[i];
            lSet[i] = temp;
        }
    }

    quickSort(lSet, start, j - 1);
    quickSort(lSet, j + 1, end);
}

int main(void) {
    int l, n, answerR = 0, answerL = 0;
    int lSet[51] = {0, };
    cin >> l;
    for(int i = 1; i < l + 1; i++)
        cin >> lSet[i];
    cin >> n;

    quickSort(lSet, 0, l);

    for(int i = 0; i < l; i++) {
        if(lSet[i] < n && lSet[i + 1] > n) {
            answerL = lSet[i];
            answerR = lSet[i + 1];
            break;
        } else if(lSet[i] == n) {
            cout << 0;
            return 0;
        }
    }

    cout << (n - answerL) * (answerR - n) - 1 << "\n";

    return 0;
}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//const int MAX = 1000 + 1;
//bool visited[MAX];
//int main(void) {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    int L, N;
//    cin >> L;
//    vector<int> luckySet(L + 1, 0);
//    for (int i = 1; i <= L; i++) {
//        cin >> luckySet[i];
//        visited[luckySet[i]] = true;
//    }
//    cin >> N;
//    if (visited[N]) {
//        cout << 0 << "\n";
//        return 0;
//    }
//    sort(luckySet.begin(), luckySet.end());
//    int left = 0;
//    int right = 0;
//
//    for (int i = 0; i < L; i++) {
//        if (luckySet[i] <= N && luckySet[i + 1] > N) {
//            left = luckySet[i];
//            right = luckySet[i + 1];
//            break;
//        }
//    }
//    cout << (N - left) * (right - N) - 1 << "\n";
//    return 0;
//}
//
