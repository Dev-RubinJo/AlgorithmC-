//
//  skillCheck2-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/05.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
string getMax(string a, string b) {
    if(a.size() == b.size()) {
        if(a > b) return a;
        else return b;
    } else {
        if(a.size() < b.size()) return b;
        return a;
    }
}
string solution(string number, int k) {
    vector<int> ind;
    string maxV = "";
    string answer = "";
    while(ind.size() != k) ind.push_back(0);
    while(ind.size() != number.size())ind.push_back(1);
    do {
        string temp = "";
        for(int i = 0; i < number.size(); i++)
            if(ind[i] == 1)
                temp += string(1, number[i]);
        maxV = getMax(temp, maxV);
    } while(next_permutation(ind.begin(), ind.end()));
    return maxV;
}
int main(void) {
    cout << solution("1924", 2) << '\n';
    cout << solution("1231234", 3) << '\n';
    cout << solution("4177252841", 4) << '\n';
    return 0;
}
