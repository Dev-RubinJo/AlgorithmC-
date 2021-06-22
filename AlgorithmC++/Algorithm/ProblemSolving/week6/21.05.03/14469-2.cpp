#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans;
vector<pair<ll, ll>> v;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        v.push_back({a, b});
    }
}

void func() {
    sort(v.begin(), v.end());
    ans = v[0].first;
    for(auto vv: v) {
        if(ans < vv.first) ans = vv.first;
        ans += vv.second;
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}