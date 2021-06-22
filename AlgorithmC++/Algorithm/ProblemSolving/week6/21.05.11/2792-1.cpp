#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans = INT_MAX;
vector<ll> v;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
}

void solve() {
    sort(v.begin(), v.end());
    ll l = 1, r = v[v.size() - 1];
    ll mid = 0;
    while(l <= r) {
        mid = (l + r) / 2;
        ll temp = 0, max_value = 0;
        for(int i = 0; i < v.size(); i++) {
            temp += v[i] / mid;
            if(v[i] % mid) temp += 1;
        }
        if(temp <= n) {
            r = mid - 1;
            ans = min(ans, mid);
        } else if(temp > n) {
            l = mid + 1;
        }
    }
    cout << ans;
}

int main(void) {
    input();
    solve();
    return 0;
}