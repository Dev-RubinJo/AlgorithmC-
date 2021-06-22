//
//  크레인 인형뽑기 게임-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/14.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    for(int i = 0; i < moves.size(); i++) {
        int top, flag = 0;
        for(int j = 0; j < board.size(); j++) {
            if(!board[j][moves[i] - 1]) {
                flag = 1;
                continue;
            }
            top = board[j][moves[i] - 1];
            board[j][moves[i] - 1] = 0;
            flag = 0;
            break;
        }
        if(flag) continue;
        if(st.empty()) st.push(top);
        else {
            if(st.top() == top) {
                st.pop();
                answer += 1;
            } else {
                st.push(top);
            }
        }
    }
    return answer * 2;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution({{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}}, {1, 5, 3, 5, 1, 2, 1, 4}) << endl;
    return 0;
}
