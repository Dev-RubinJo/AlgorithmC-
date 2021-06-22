//
//  완주하지 못한 선수-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/14.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m1;
    for(int i = 0; i < participant.size(); i++)
        m1[participant[i]] += 1;
    for(int i = 0; i < completion.size(); i++) {
        m1[completion[i]] -= 1;
    }
    for(auto it: m1) {
        if(it.second) {
            answer = it.first;
            break;
        }
    }
    return answer;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << endl;
    return 0;
}
