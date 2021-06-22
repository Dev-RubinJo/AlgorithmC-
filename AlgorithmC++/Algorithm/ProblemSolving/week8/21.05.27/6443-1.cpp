#include <bits/stdc++.h>
using namespace std;
int n;
int alphas[26];
string s;
char tmp[100001];

void func(int cnt) {
    if (cnt == s.size()) {
        cout << tmp << '\n';
        return;
    }
 
    for (int i = 0; i < 26; i++) {
        if (alphas[i] > 0) {
            alphas[i]--;
            tmp[cnt] = 'a' + i;
            func(cnt + 1);
            alphas[i]++;
        }
    }
}

void input() {
    cin >> n;
    while(n) {
        cin >> s;
        for (int i = 0; i < 26; i++)
            alphas[i] = 0;
        for (int i = 0; i < s.size(); i++) {
            alphas[s[i] - 'a']++;
        }
        func(0);
        n -= 1;
    }
}

int main(void) {
    input();
    return 0;
}