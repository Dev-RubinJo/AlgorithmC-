#include <bits/stdc++.h>
using namespace std;
int n, m;
string dp[101][101];

void input() {
    cin >> n >> m;
}

string add(string a, string b) {
    int carry = 0;
    string res;
    while(!a.empty() || !b.empty() || carry) {
        if(!a.empty()) {
            carry += a.back() - '0';
            a.pop_back();
        }
        if(!b.empty()) {
            carry += b.back() - '0';
            b.pop_back();
        }
        res.push_back((carry % 10) + '0');
        carry /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string combi(int n, int r) {
    if(n == r || r == 0) {
        return "1";
    }
    string &res = dp[n][r];
    if(res != "") return res;
    res = add(combi(n - 1, r - 1), combi(n - 1, r));
    return res;
}

int main(void) {
    input();
    cout << combi(n, m);
    return 0;
}