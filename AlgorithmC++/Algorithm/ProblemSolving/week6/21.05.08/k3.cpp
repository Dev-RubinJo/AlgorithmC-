#include <bits/stdc++.h>
using namespace std;
bool v[1000001];
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    for(int i = 0; i < n; i++) {
        v[i] = 1;
    }
    int len = n, left = 0, right = 0;
    deque<int> q;
    for(int i = 0; i < cmd.size(); i++) {
        if(cmd[i][0] == 'U') {
            int temp = stoi(cmd[i].substr(2, cmd[i].size() - 2));
            if(k - temp >= 0) {
                for(int j = 1; j <= temp; j++) {
                    k -= 1;
                    if(!v[k]) j -= 1;
                }
            }
        } else if(cmd[i][0] == 'D') {
            int temp = stoi(cmd[i].substr(2, cmd[i].size() - 2));
            if(k + temp < len) {
                for(int j = 1; j <= temp; j++) {
                    k += 1;
                    if(!v[k]) j -= 1;
                }
            }
        } else if(cmd[i][0] == 'C') {
            v[k] = 0;
            q.push_back(k);
            if(k == len - 1) {
                k -= 1;
                len -= 1;
            }
            else
                k += 1;
        } else if(cmd[i][0] == 'Z') {
            int temp = q.back(); q.pop_back();
            v[temp] = 1;
            if(temp == len) len += 1;
        }
    }
    for(int i = 0; i < n; i++) {
        if(v[i]) answer += "O";
        else answer += "X";
    }
    return answer;
}

int main(void) {
    cout << solution(8, 7, {"C", "C", "C", "Z", "U 3", "C", "D 1", "C", "Z"});
    return 0;
}