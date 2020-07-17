//
//  Stack.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/17.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    
    s.push(7);
    s.push(5);
    s.push(4);
    s.pop();
    s.push(6);
    s.pop();
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}
