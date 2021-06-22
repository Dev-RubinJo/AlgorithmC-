//
//  2529-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/13.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
char op[9];
ll n, maxI, minI = 999999999999999;
string maxS, minS;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> op[i];
    do {
        int flag = 0;
        for(int i = 0; i < n; i++) {
            if(op[i] == '<') {
                if(numbers[i] > numbers[i + 1]) {
                    flag = 1;
                    break;
                }
            } else {
                if(numbers[i] < numbers[i + 1]) {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) continue;
        string temp = "";
        for(int i = 0; i < n + 1; i++) temp += to_string(numbers[i]);
        if(maxI < stoll(temp)) {
            maxI = stoll(temp);
            maxS = temp;
        }
        if(minI > stoll(temp)) {
            minI = stoll(temp);
            minS = temp;
        }
    } while(next_permutation(numbers, numbers + 10));
    
    cout << maxS << endl << minS;
    return 0;
}
