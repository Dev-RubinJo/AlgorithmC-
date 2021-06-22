#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, nidx;
ll ans;
vector<pair<ll, ll>> ns;
vector<ll> ks;
priority_queue<ll> pq;
void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        ns.push_back({a, b});
    }
    for(int i = 0; i < k; i++) {
        ll a; cin >> a;
        ks.push_back(a);
    }
}

void func() {
    sort(ns.begin(), ns.end());
    sort(ks.begin(), ks.end());
    for(int i = 0; i < k; i++) {
        while(nidx <= n && ks[i] >= ns[nidx].first) {
            pq.push(ns[nidx].second);
            nidx += 1;
        }
        if(!pq.empty()) {
            ans += pq.top(); pq.pop();
        }
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}