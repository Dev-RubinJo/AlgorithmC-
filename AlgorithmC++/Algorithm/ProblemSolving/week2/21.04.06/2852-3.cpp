//
//  2852-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, a, b, w, asum, bsum;
string s, pre;
void printTime(int sum) {
    string mm = "00" + to_string(sum / 60);
    string ss = "00" + to_string(sum % 60);
    cout << mm.substr(mm.size() - 2, 2) + ":" + ss.substr(ss.size() - 2, 2) + "\n";
}
void calculate(int &sum, string tem) {
    sum += abs((stoi(tem.substr(0, 2)) - stoi(pre.substr(0, 2))) * 60 + (stoi(tem.substr(3, 2)) - stoi(pre.substr(3, 2))));
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> w >> s;
        if(a > b) calculate(asum, pre);
        else if(a < b) calculate(bsum, pre);
        (w == 1) ? a += 1 : b += 1;
        pre = s;
    }
    if(a > b) calculate(asum, "48:00");
    else if(a < b) calculate(bsum, "48:00");
    printTime(asum);
    printTime(bsum);
    return 0;
}
