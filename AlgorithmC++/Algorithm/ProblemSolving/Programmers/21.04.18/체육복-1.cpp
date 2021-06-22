//
//  체육복-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/18.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int student[35] = {0, };
    for(int i: reserve) student[i] += 1;
    for(int i: lost) student[i] += -1;
    for(int i = 1; i <= n; i++) {
        if(student[i] == -1) {
            if(student[i-1] == 1)
                student[i-1] = student[i] = 0;
            else if(student[i+1] == 1)
                student[i] = student[i+1] = 0;
        }
    }
    for(int i = 1; i <= n; i++)
        if(student[i] != -1) answer++;

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution(5, {2, 4}, {1, 3, 5}) << endl;
    cout << solution(5, {2, 4}, {3}) << endl;
    cout << solution(3, {3}, {1}) << endl;
    return 0;
}
/*
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    for(int i = 0; i < lost.size(); i++) {
        auto fit = find(reserve.begin(), reserve.end(), lost[i] - 1);
        auto eit = find(reserve.begin(), reserve.end(), lost[i] + 1);
        if(fit != reserve.end()) {
            answer += 1;
            reserve.erase(fit);
        } else if (eit != reserve.end()) {
            answer += 1;
            reserve.erase(eit);
        }
    }
    return answer;
}
*/
