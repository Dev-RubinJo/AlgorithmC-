#include <bits/stdc++.h>
using namespace std;
int n, cmd;
deque<int> dq;
string s;

void func() {
    cin >> n;
    while(n) {
        cin >> s;
        if(s == "push_back") {
            cin >> cmd;
            dq.push_back(cmd);
        } else if(s == "push_front") {
            cin >> cmd;
            dq.push_front(cmd);
        } else if(s == "front") {
            if(dq.size()) {
                cout << dq.front() << "\n";
            } else {
                cout << -1 << '\n';
            }
        } else if(s == "back") {
            if(dq.size()) {
                cout << dq.back() << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if(s == "size") {
            cout << dq.size() << '\n';
        } else if(s == "empty") {
            cout << (int)dq.empty() << '\n';
        } else if(s == "pop_front") {
            if(dq.size()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            } else {
                cout << -1 << '\n';
            }
        } else if(s == "pop_back") {
            if(dq.size()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            } else {
                cout << -1 << '\n';
            }
        }
        n -= 1;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    func();
    return 0;
}