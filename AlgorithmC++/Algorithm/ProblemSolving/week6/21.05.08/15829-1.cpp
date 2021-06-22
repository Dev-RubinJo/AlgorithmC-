#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, a[51], b = 1234567891, ans;
string s;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> l;
    cin >> s;
    for(int i = 0; i < l; i++)
        a[i] = s[i] - 'a' + 1;
}

void solve() {
    for(int i = 0; i < l; i++) {
        ll temp = 1;
        for(int j = 0; j < i; j++) {
            temp *= 31 ;
            temp %= b;
        }
        ans += a[i] * temp % b;
    }
    cout << ans % b;
}

int main(void) {
    input();
    solve();
    return 0;
}