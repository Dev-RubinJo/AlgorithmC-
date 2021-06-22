#include <bits/stdc++.h>
using namespace std;
string king, stone, cmd;
int n;
pair<int, int> k, s;

void move(int x, int y) {
    if(k.first + x < 0 || k.first + x >= 8 || k.second + y < 0 || k.second + y >= 8) return;
    if(k.first + x == s.first && k.second + y == s.second) {
        if(s.first + x < 0 || s.first + x >= 8 || s.second + y < 0 || s.second + y >= 8) return;
        s.first += x; s.second += y;
    }
    k.first += x; k.second += y;
}

void input() {
    cin >> king >> stone >> n;
    k.first = king[0] - 'A';
    k.second = king[1] - '1';
    s.first = stone[0] - 'A';
    s.second = stone[1] - '1';
    for(int i = 0; i < n; i++) {
        cin >> cmd;
        if(cmd == "R") {
            move(1, 0);
        } else if(cmd == "L") {
            move(-1, 0);
        } else if(cmd == "B") {
            move(0, -1);
        } else if(cmd == "T") {
            move(0, 1);
        } else if(cmd == "RT") {
            move(1, 1);
        } else if(cmd == "LT") {
            move(-1, 1);
        } else if(cmd == "RB") {
            move(1, -1);
        } else if(cmd == "LB") {
            move(-1, -1);
        }
    }
    cout << (char)(k.first + 'A') << (char)(k.second + '1') << "\n" << (char)(s.first + 'A') << (char)(s.second + '1');
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    return 0;
}
