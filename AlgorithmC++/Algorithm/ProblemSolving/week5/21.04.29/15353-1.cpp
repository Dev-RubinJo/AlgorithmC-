#include <bits/stdc++.h>
using namespace std;
string s1, s2, ans;
int carry, idx;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s1 >> s2;
    
    while(s1.size() || s2.size() || carry) {
        if(s1.size()) {
            carry += s1.back() - '0';
            s1.pop_back();
        }
        if(s2.size()) {
            carry += s2.back() - '0';
            s2.pop_back();
        }
        ans += to_string(carry % 10);
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}