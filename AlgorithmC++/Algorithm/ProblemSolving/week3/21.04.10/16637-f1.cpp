//
//  16637-f1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/10.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, numSize, opSize, maxS;
int nums[11], op[10], orders[10], orderTemp[10];
char c;
void solution() {
    for(int i = 0; i < opSize; i++) {
        orders[i] = i;
        int flag = 0;
        do {
            for(int i = 1; i < (opSize + 1) / 2; i++) {
                if(orders[i] == orders[i - 1]) flag = 1;
            }
            if (flag) continue;
            vector<int> v1, v2;
            for(int i = 0; i < numSize; i++) v1.push_back(nums[i]);
            for(int i = 0; i < opSize; i++) v2.push_back(op[i]);
            for(int i = 0; i < opSize; i++) orderTemp[i] = orders[i];
            int i = 0;
            while(!v2.empty()) {
                int index = orderTemp[i];
                int oper = v2[index];
                if(oper == 1)
                    v1[index] +=  v1[index + 1];
                else if(oper == 2)
                    v1[index] -= v1[index + 1];
                else if (oper == 3)
                    v1[index] *= v1[index + 1];
                v1.erase(v1.begin() + index + 1);
                v2.erase(v2.begin() + index);
                i += 1;
                for(int j = 0; j < opSize; j++)
                    if(orderTemp[i] > index) orderTemp[i] -= 1;
            }
            maxS = max(maxS, v1[0]);
        } while(next_permutation(orders, orders + opSize));
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c;
        if(c - '0' >= 0 && c - '0' <= 9) { nums[numSize] = c - '0'; numSize += 1; }
        else {
            if(c == '+') op[opSize] = 1;
            else if(c == '-') op[opSize] = 2;
            else if(c == '*') op[opSize] = 3;
            opSize += 1;
        }
    }
    solution();
    cout << maxS;
    return 0;
}
// TODO: 틀림
