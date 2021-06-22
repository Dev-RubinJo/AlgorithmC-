#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans;
vector<int> v;
bool a[100001];
void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        v.push_back(t);
    }
}

void func() {
    ll l = 0, r = 0;
    while(r < n) {
        if(!a[v[r]]) {
            a[v[r]] = 1;
            r += 1;
        } else {
            ans += r - l;
            a[v[l]] = 0;
            l += 1;
        }
    }
    ans += (r - l) * (r - l + 1) / 2;
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}