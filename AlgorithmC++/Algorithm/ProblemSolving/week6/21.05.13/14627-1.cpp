#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, c, ans = INT_MAX, lo, hi;
vector<ll> v;

void input() {
    cin >> s >> c;
    for(int i = 0; i < s; i++) {
        ll tmp; cin >> tmp;
        v.push_back(tmp);
        hi = max(tmp, hi);
    }
}

void func() {
    // sort(v.begin(), v.end());
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for(ll vv: v) {
            cnt += vv / mid;
        }
        if(cnt < c) {
            hi = mid - 1;
        } else if(cnt > c) {
            lo = mid + 1;
        } else {
            ll tmp = 0;
            // cout << mid << " " << hi << " " << lo << '\n';
            for(ll vv: v) {
                tmp += vv % mid;
            }
            lo = mid + 1;
            // cout << tmp << '\n';
            ans = min(tmp, ans);
        }
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}