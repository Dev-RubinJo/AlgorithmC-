//
//  10988-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//string s, pre, suf;
//int main(void) {
//    cin >> s;
//
//    if (s.size() % 2) {
//        pre = s.substr(0, s.size() / 2);
//        suf = s.substr(s.size() / 2 + 1, s.size() / 2);
//    } else {
//        pre = s.substr(0, s.size() / 2);
//        suf = s.substr(s.size() / 2, s.size() / 2);
//    }
//    reverse(suf.begin(), suf.end());
//    cout << (pre == suf) ? 1 : 0;
//
//
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;
string s, temp;
int main(void) {
    cin >> s;
    temp = s;
    reverse(temp.begin(), temp.end());
    cout << (s == temp) ? 1 : 0;
    return 0;
}
