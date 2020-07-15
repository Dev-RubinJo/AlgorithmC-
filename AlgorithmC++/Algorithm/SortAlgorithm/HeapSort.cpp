//
//  HeapSort.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/12.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int num = 9;
    int a[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};
    
    // max 힙 구조로 만들기
    for(int i = 1; i < num; i++) {
        int c = i;
        do {
            int root = (c - 1) / 2;
            if(a[root] < a[c]) {
                int temp = a[root];
                a[root] = a[c];
                a[c] = temp;
            }
            c = root;
        } while(c != 0);
    }
    
    // 크기를 줄여가며 반복적으로 힙을 구성
    for(int i = num - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        int root = 0;
        int c = 1;
        do {
            c = 2 * root + 1;
            // 자식중에 더 큰값을 찾기
            if(a[c] < a[c + 1] && c < i - 1) {
                c++;
            }
            // 루트보다 자식이 더 크다면 교환
            if (a[root] < a[c] && c < i) {
                int temp = a[root];
                a[root] = a[c];
                a[c] = temp;
            }
            root = c;
        } while(c < i);
    }
    
    for(int i = 0; i < num; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}

// MARK: - 힙정렬 설명
/*
 힙정렬은 병합정렬과 퀵정렬만큼 빠른 정렬이다. 힙정렬은 힙트리 구조를 이용하는 정렬 방법
힙 트리를 알기 위해서는 이진 트리를 알아야한다
 MARK: 이진트리: 모든 노드의 자식 노드가 2개 이하인 트리 구조
 힙정렬은 완전 이진트리를 이용해서 구한다
 
 
 */
