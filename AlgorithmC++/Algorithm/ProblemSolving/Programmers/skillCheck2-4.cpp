//
//  skillCheck2-4.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/07.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
bool compair(string a, string b) {
    return a + b > b + a; // MARK: 문자열 두개를 합치는 순서에 따른 값을 확인할 수 있는게 제일 중요한 아이디어.
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(auto a: numbers)
        v.push_back(to_string(a));
    sort(v.begin(), v.end(), compair);
    for(auto a: v)
        answer += a;
    if(answer[0] == '0') {
        answer = "0";
    }
    return answer;
}

int main(void) {
    cout << solution({6, 10, 2}) << '\n';
    cout << solution({10, 10, 100}) << '\n';
    cout << solution({3, 30, 34, 5, 9}) << '\n';
    cout << solution({0, 0, 0, 0}) << '\n';
    return 0;
}
//bool compair(string a, string b) {
//    if(a[0] > b[0]) return true;
//    else {
//        for(int i = 0; i < a.size(); i++) {
//            for(int j = 0; j < b.size(); j++) {
//                if(a[i] > b[j]) return a[i] > b[j];
//                else if(a[i] < b[j]) return false;
//            }
//        }
//        return false;
//    }
//}
//string compair(string a, string b) {
//    if(a.size() == b.size()) {
//        if(a > b) return a;
//        else return b;
//
//    } else {
//        if(a.size() > b.size()) return a;
//        else return b;
//    }
//}
//    vector<string> v;
//    sort(numbers.begin(), numbers.end());
//    for(auto n: numbers) v.push_back(to_string(n));
//    do {
//        string temp = "";
//        for(int i = 0; i < numbers.size(); i++) temp += to_string(numbers[i]);
//        answer = compair(answer, temp);
//    } while(next_permutation(numbers.begin(), numbers.end()));
