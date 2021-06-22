#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans = 1e18;
vector<ll> v;

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        ll tmp; cin >> tmp;
        v.push_back(tmp);
    }
}

bool check(ll mid) {
    ll cnt = 0;
    for(int i = 0; i < m; i++) {
        cnt += v[i] / mid;
        if(v[i] % mid) cnt += 1;
    }
    return n >= cnt;
}

void func() {
    ll lo = 1, hi = 1e9;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        cout << lo << " " << hi << " " << mid << " " << ans << '\n';
        if(!check(mid)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
            ans = min(ans, mid);
        }
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}