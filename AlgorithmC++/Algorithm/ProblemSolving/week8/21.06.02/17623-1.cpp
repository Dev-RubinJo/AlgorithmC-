#include <bits/stdc++.h>
using namespace std;
int tc, n;
string dp[1001];
map<char, char> m1;

void setup() {
    m1['1'] = '(';
    m1['2'] = ')';
    m1['3'] = '{';
    m1['4'] = '}';
    m1['5'] = '[';
    m1['6'] = ']';
    dp[1] = "12";
    dp[2] = "34";
    dp[3] = "56";
}

bool check(string a, string b) { // a가 더 클때 바꿔줄 수 있도록 하기 위함
    if(a == "" && b == "") return false;
    if(a == "") return true;
    if(a.size() > b.size()) return true;
    else if(a.size() < b.size()) return false;
    return a > b;
}

void func() {
    for(int i = 1; i <= 1000; i++) {
        if(i % 2 == 0 && check(dp[i], '1' + dp[i / 2] + '2')) {
            dp[i] = '1' + dp[i / 2] + '2';
        }
        if(i % 3 == 0 && check(dp[i], '3' + dp[i / 3] + '4')) {
            dp[i] = '3' + dp[i / 3] + '4';
        }
        if(i % 5 == 0 && check(dp[i], '5' + dp[i / 5] + '6')) {
            dp[i] = '5' + dp[i / 5] + '6';
        }
        for(int j = 1; j <= i; j++) {
            if(check(dp[i], dp[j] + dp[i - j])) {
                dp[i] = dp[j] + dp[i - j];
            }
        }
    }
}

void input() {
    cin >> tc;
    while(tc) {
        tc -= 1;
        cin >> n;
        for(char ch: dp[n]) {
            cout << m1[ch];
        }
        cout << '\n';
    }
}

int main(void) {
    setup();
    func();
    input();
    return 0;
}