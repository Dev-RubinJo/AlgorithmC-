//
//  ReverseInteger.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/12.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        int answer = 0;
        while(x != 0) {
            if(answer > INT_MAX / 10 || (answer == INT_MAX / 10 && x > 7)) return 0;
            if(answer < INT_MIN / 10 || (answer == INT_MIN / 10 && x < -8)) return 0;
            answer = (answer * 10) + x % 10;
            x /= 10;
        }

        return answer;
    }
};

int main(void) {
    Solution s;
    cout << s.reverse(-2147483648);
    
    return 0;
}
