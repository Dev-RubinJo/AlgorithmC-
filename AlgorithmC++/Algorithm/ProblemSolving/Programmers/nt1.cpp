//
//  nt1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string solution(int n, vector<int> p, vector<int> c) {
    int cnt = 0, res = 0, last = 0;
    float ans;
    for(int i = 0; i < n; i++) {
        int total = last + p[i];
        if(total >= c[i]) {
            last = total - c[i];
            if(cnt == 1)
                res += c[i] * 50;
            else if(cnt == 2)
                res += c[i] * 25;
            else if(!cnt)
                res += c[i] * 100;
            cnt = 0;
        } else {
            cnt += 1;
            last = total;
        }
        if (cnt > 2) {
            n = i + 1;
            break;
        }
    }
    ans = (float)res / (float)n;
    string answer = to_string(round(ans * 100) / 100);
    return answer.substr(0, answer.find(".") + 3);
}
int main(void) {
    cout << solution(10, {5, 4, 7, 2, 0, 6, 1, 2, 3, 4}, {4, 6, 4, 9, 2, 3, 9, 1, 9, 9}) << "\n";
    cout << solution(7, {6, 2, 1, 0, 2, 4, 3}, {3, 6, 6, 2, 3, 7, 6}) << "\n";
    return 0;
}
