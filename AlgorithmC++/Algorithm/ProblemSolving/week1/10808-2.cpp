//
//  10808-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/26.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int alphas[26];
//string s;
//
//int main(void) {
//
//    cin >> s;
//    for(int i = 0; i < s.size(); i++) {
//        alphas[s[i] - 'a'] += 1;
//    }
//
//    for(int i = 0; i < 26; i++) {
//        cout << alphas[i] << " ";
//    }
//
//    return 0;
//}


#include <bits/stdc++.h>
using namespace std;

int cnt[26];
string str;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str;
    for(char c: str)
        cnt[c - 'a'] += 1;
    for(int i = 0; i < 26; i++) cout << cnt[i] << " ";
    return 0;
}
