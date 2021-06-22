#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, heroH, heroA, ans;
ll t[130000], a[130000], h[130000];

bool check(ll mid) {
    ll tmpHeroA = heroA;
    ll tmpH = mid;
    for(int i = 0; i < n; i++) {
        if(t[i] == 2) {
            tmpH = min(mid, tmpH + h[i]);
            tmpHeroA += a[i];
        } else {
            ll tmp = h[i] / tmpHeroA;
            if(h[i] % tmpHeroA) {
                tmp += 1;
            }
            tmpH -= a[i] * (tmp - 1);
        }
        if(tmpH <= 0) return false; 
    }
    return true;
}

int main(void) {
    cin >> n >> heroA;
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> h[i];
    }
    ll lo = 1; ll hi = 1e18;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans;
    return 0;
}