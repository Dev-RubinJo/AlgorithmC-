//
//  BaekJoon1744.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/18.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int a, int b) {
    return a > b;
}

using namespace std;

int main(void) {
    int n, answer = 0, temp;
    vector<int> positive;
    vector<int> negative;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp <= 0)
            negative.push_back(temp);
        else if(temp == 1)
            answer += 1;
        else
            positive.push_back(temp);
    }
    sort(positive.begin(), positive.end(), compare);
    sort(negative.begin(), negative.end());
    
    for(int i = 0; i < negative.size(); i++) {
        if(i + 1 < negative.size())
            answer += negative[i] * negative[i + 1];
        else
            answer += negative[i];
        i += 1;
    }
    for(int i = 0; i < positive.size(); i++) {
        if(i + 1 < positive.size())
            answer += positive[i] * positive[i + 1];
        else
            answer += positive[i];
        i += 1;
    }
    
    cout << answer;
    
    return 0;
}
