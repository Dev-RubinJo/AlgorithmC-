//
//  완주하지 못한 선수-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/14.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int ans[100001];
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(auto s: participant) {
        auto it = find(completion.begin(), completion.end(), s);
        if(it != completion.end()) {
            completion.erase(it);
        } else {
            answer = s;
        }
    }
    
    return answer;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << endl;
    return 0;
}
// MARK: 효율성을 통과하지 못한 코드
