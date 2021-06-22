#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, lo, hi, ans = 1e18;
vector<ll> v;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        v.push_back(tmp);
        lo = max(lo, tmp);
        hi += tmp;
    }
}

bool check(ll mid) {
    ll cnt = 0, tmp = 0;
    for(int i = 0; i < n; i++) {
        if(tmp + v[i] > mid) {
            tmp = 0;
            cnt += 1;
        }
        tmp += v[i];
    }
    cnt += 1;
    return cnt <= m;
}

void func() {
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        // cout << lo << " " << hi << " " << mid << " " << ans << '\n';
        if(check(mid)) {
            ans = min(ans, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}