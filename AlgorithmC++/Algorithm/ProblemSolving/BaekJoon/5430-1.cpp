//
//  5430-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/07.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int tc, n;
string cmd, s;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        deque<int> m;
        int flag = 0;
        string temp = "";
        cin >> cmd;
        cin >> n;
        cin >> s;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9) temp += string(1, s[i]);
            else {
                if(temp != "") m.push_back(stoi(temp));
                temp = "";
            }
        }
        int rcnt = 0;
        for(int i = 0; i < cmd.size(); i++) {
            if(cmd[i] == 'R') rcnt += 1;
            else {
                if(m.empty()) {
                    flag = 1;
                    break;
                } else {
                    if(rcnt % 2) m.pop_back();
                    else m.pop_front();
                }
            }
        }
        if(flag) cout << "error\n";
        else {
            string res = "";
            res += "[";
            if(rcnt % 2) {
                while(!m.empty()) {
                    res += to_string(m.back()) + ",";
                    m.pop_back();
                }
            } else {
                while(!m.empty()) {
                    res += to_string(m.front()) + ",";
                    m.pop_front();
                }
            }
            if(res[res.size() - 1] == ',') res.erase(res.end() - 1);
            res += "]\n";
            cout << res;
        }
    }
    return 0;
}
// MARK: deque를 이용하여 풀 수 있던 문제, tc의 수와 각 테스트마다 수의 개수를 생각하면 그냥 sort로 푸는건 무모하다. 따라서 양방향 넣고 빼기가 가능한 deque를 이용해서 sort로 걸릴 시간을 최소화 시킨다.
