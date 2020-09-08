//
//  Fibonacci.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/26.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

//int fibonacci(int i) {
//    if(i <= 1) return 1;
//    return fibonacci(i - 1) + fibonacci(i - 2);
//}

long long fibonacci(long long a[], int i) {
    if(i <= 1) return 1;
    if(a[i] != 0) return a[i];
    return a[i] =  fibonacci(a, i - 1) + fibonacci(a, i - 2);
}

long long fibonacciFor(int a) {
    long long ans = 0;
    long long first = 1, second = 1;
    for(int i = 3; i <= a; i++) {
        ans = first + second;
        first = second;
        second = ans;
    }

    return ans;
}

int main(void) {
    
    long long fibo[10000] = {0, };
//    cout << fibonacci(fibo, 100);

    cout << fibonacciFor(90);
    
    return 0;
}
