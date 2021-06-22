//
//  11655-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

string str;

int main(void) {
    getline(cin, str);
    for(int i = 0; i < str.size(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            if(str[i] + 13 > 'Z') str[i] = str[i] - 13;
            else str[i] += 13;
        } else if(str[i] >= 'a' && str[i] <= 'z') {
            if(str[i] + 13 > 'z') str[i] = str[i] - 13;
            else str[i] += 13;
        }
    }
    cout << str;
    return 0;
}

//int main(void) {
//    getline(cin, str);
//    for(int i = 0; i < str.size(); i++) {
//        if(str[i] >= 'A' && str[i] <= 'Z') {
//            str[i] = (char)(str[i] + 13);
//            if (str[i] > 90)
//                str[i] -= 26;
//            cout << str[i];
//        } else if (str[i] >= 'a' && str[i] <= 'z') {
//            str[i] = (char)(str[i] + 13); // MARK: 먼저 하지말고 비교를 먼저하자
//            if (str[i] > 122)
//                str[i] -= 26;
//            cout << str[i];
//        } else
//            cout << str[i];
//    }
//    return 0;
//}

