#include <bits/stdc++.h>
using namespace std;
string str, bomb;
deque<char> dq;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str >> bomb;
}

void func() {
    for(int i = 0; i < str.size(); i++) {
        dq.push_back(str[i]);
        if(dq.size() >= bomb.size() && dq.back() == bomb[bomb.size() - 1]) {
            int bidx = bomb.size() - 1, dqidx = dq.size() - 1, flag = 0;
            while(bidx >= 0) {
                if(bomb[bidx] != dq[dqidx]) {
                    flag = 1;
                    break;
                }
                bidx -= 1; dqidx -= 1;
            }
            if(!flag) {
                for(int i = 0; i < bomb.size(); i++) {
                    dq.pop_back();
                }
            }
        }
    }

    if(dq.size()) {
        while(dq.size()) {
            cout << dq.front(); dq.pop_front();
        }
    } else {
        cout << "FRULA";
    }
}
int main(void) {
    input();
    func();
    return 0;
}