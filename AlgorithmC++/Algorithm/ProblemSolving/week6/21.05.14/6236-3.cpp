#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans = 1e18, lo, hi, total;
vector<ll> v;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        v.push_back(tmp);
        hi += tmp;
        lo = max(lo, tmp);
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
        if(check(mid)) {
            hi = mid - 1;
            ans = min(mid, ans);
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