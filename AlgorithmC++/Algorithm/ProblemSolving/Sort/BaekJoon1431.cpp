//
//  BaekJoon1431.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/14.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int getSum(string a) {
    int n = a.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] - '0' <= 9 && a[i] - '0' >= 0) { // 이 생각을 해내기가 어렵다
            sum += (a[i] - '0');
        }
    }
    return sum;
}

bool compare(string a, string b) {
    if(a.size() < b.size()) {
        return true;
    } else if (a.size() > b.size()) {
        return false;
    } else {
        int aSum = getSum(a);
        int bSum = getSum(b);
        
        if(aSum != bSum) {
            return aSum < bSum;
        } else
            return a < b;
        
    }
    
    return a < b;
}

int main() {
    
    int n;
    string str[1000];
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    
    sort(str, str + n, compare);
    
    for(int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
    
    return 0;
}
