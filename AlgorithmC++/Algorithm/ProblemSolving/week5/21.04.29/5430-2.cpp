#include <bits/stdc++.h>
using namespace std;
int t, n, d;
string s, nums;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int tc = 0; tc < t; tc++) {
        deque<int> dq; int temp = 0, flag = 0; d = 0;
        cin >> s >> n >> nums;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == '[') continue;
            if(nums[i] == ',' || nums[i] == ']') {
                dq.push_back(temp);
                temp = 0;
            } else {
                temp = temp * 10 + nums[i] - '0';
            }
            if(!dq.empty() && dq.back() == 0) dq.pop_back();
        }
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'R') d = !d;
            else if(s[i] == 'D') {
                if(dq.empty()) { flag = 1; break; }
                else {
                    if(d) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }
        if(flag) cout << "error\n";
        else {
            string res = "";
            res += "[";
            while(!dq.empty()) {
                if(d) { res += to_string(dq.back()); dq.pop_back(); }
                else { res += to_string(dq.front()); dq.pop_front(); }
                res += ",";
            }
            if(res[res.size() - 1] == ',') res.erase(res.end() - 1);
            res += "]";
            cout << res << '\n';
        }
        // for(int a: dq) cout << a << ' ';
        // cout << '\n';
    }
    return 0;
}