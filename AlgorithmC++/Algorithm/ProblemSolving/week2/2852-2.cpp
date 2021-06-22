//
//  2852-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/05.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, w, a, b, at, bt;
string s, temp;
string print(int time) {
    int mm = time / 60;
    int ss = time % 60;
    string strmm = ("00" + to_string(mm));
    string strss = ("00" + to_string(ss));
    return strmm.substr(strmm.size() - 2, 2) + ":" + strss.substr(strss.size() - 2, 2);
}
void calculate(int &sum, string s) {
    sum += (stoi(s.substr(0, 2)) - stoi(temp.substr(0, 2))) * 60 + (stoi(s.substr(3, 2)) - stoi(temp.substr(3, 2)));
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> w >> s;
        if(a > b) calculate(at, s);
        else if(a < b) calculate(bt, s);
        (w == 1) ? a += 1 : b += 1;
        temp = s;
    }
    if(a > b) calculate(at, "48:00");
    else if(a < b) calculate(bt, "48:00");
    cout << print(at) << "\n" << print(bt);
    return 0;
}
