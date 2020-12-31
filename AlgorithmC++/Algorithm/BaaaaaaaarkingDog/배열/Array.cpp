//
//  Array.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/12/31.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void insert(int idx, int num, int arr[], int& len);
void erase(int idx, int arr[], int& len);
void printArr(int arr[], int& len);

void insert_test(){
  cout << "***** insert_test *****\n";
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); // 10 20 30 40
  printArr(arr, len);
  insert(1, 50, arr, len); // 10 50 20 30 40
  printArr(arr, len);
  insert(0, 15, arr, len); // 15 10 50 20 30 40
  printArr(arr, len);
}

void erase_test(){
  cout << "***** erase_test *****\n";
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); // 10 50 40 30 20
  printArr(arr, len);
  erase(1, arr, len); // 10 40 30 20
  printArr(arr, len);
  erase(3, arr, len); // 10 40 30
  printArr(arr, len);
}

int a[21];
int b[21][21];


int main(void) {
    
    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    insert(3, 60, arr, len);
    printArr(arr, len);
    
    erase(4, arr, len);
    printArr(arr, len);
    
    insert_test();
    erase_test();
    
    // 1번 배열 채우기 방식 (일단 이런게 있다라는 것을 알아둘 방식)
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    
    // 2번 배열 채우기 방식 (제일 무난)
    for (int i = 0; i < 21; i++) {
        a[i] = 0;
    }
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            b[i][j] = 0;
        }
    }
    
    // 3번 배열 채우기 방식 (익숙해지면 좋은 방식)
    fill(a, a + 21, 0);
    for (int i = 0; i < 21; i++) {
        fill(b[i], b[i] + 21, 0);
    }
    
    return 0;
}

void insert(int idx, int num, int arr[], int& len) {
    for (int i = len - 1; i >= idx; i--) {
        arr[i + 1] = arr[i];
    }
    arr[idx] = num;
    len++;
}

void erase(int idx, int arr[], int& len) {
    for (int i = idx; i < len; i++) {
        arr[i] = arr[i + 1];
    }
    arr[len] = NULL;
    len--;
}

void printArr(int arr[], int& len) {
    for (int i = 0; i < len; i++) cout << arr[i] << ' ';
    cout << "\n\n";
}
