#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, tree[1000001], ans, lo, hi;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> tree[i];
        hi = max(hi, tree[i]);
    }
}

bool check(ll mid) {
    ll res = 0;
    for(int i = 0; i < n; i++) {
        res += (tree[i] - mid >= 0 ? tree[i] - mid : 0);
    }
    return res >= m;
}

void func() {
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        // cout << lo << " " << hi << " " << mid << " " << "\n";
        if(check(mid)) {
            ans = max(ans, mid);
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

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, tree[1000001], ans, lo, hi;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> tree[i];
        hi = max(hi, tree[i]);
    }
}

void func() {
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll res = 0;
        for(int i = 0; i < n; i++) {
           res += tree[i] - mid;
        }
        cout << lo << " " << hi << " " << mid << " " << res << "\n";
        if(res > m) {
            lo = mid + 1;            
        } else if(res < m) {
            hi = mid - 1;
        } else {
            ans = mid;
        }
    }

    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}
*/