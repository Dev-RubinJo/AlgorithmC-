//
//  skillCheck2-3.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/07.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    char last = '\0';
    vector<int> answer;
    int idx = 0;
    vector<string> v;
    for(auto w: words) {
        auto it = find(v.begin(), v.end(), w);
        if(it == v.end() && (last == w[0] || last == '\0')) {
            last = w[w.size() - 1];
            idx += 1;
            v.push_back(w);
        } else
            break;
    }
    if(idx != words.size()) {
        answer.push_back(idx % n + 1);
        answer.push_back(idx / n + 1);
    } else {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
int main(void) {
//    vector<int> res = solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});
//    vector<int> res = solution(5, {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"});
    vector<int> res = solution(2, {"hello", "one", "even", "never", "now", "world", "draw"});
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
