#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, n, lan[10001], ans;

void input() {
    cin >> k >> n;
    for(int i = 0; i < k; i++) {
        cin >> lan[i];
    }
}

bool check(ll mid) {
    ll cnt = 0;
    for(int i = 0; i < k; i++) {
        cnt += lan[i] / mid;
    }
    return cnt >= n;
}

void func() {
    sort(lan, lan + k);
    ll lo = 1, hi = lan[k - 1];
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        // cout << lo << " " << hi << " " << mid << '\n';
        if(check(mid)) {
            ans = max(mid, ans);
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}