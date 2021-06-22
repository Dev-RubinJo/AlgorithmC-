#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, nidx, ans;
vector<pair<int, int>> ns;
vector<int> ks;
priority_queue<int> pq;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        ns.push_back({a, b});
    }
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        ks.push_back(a);
    }
}

void solve() {
    sort(ns.begin(), ns.end());
    sort(ks.begin(), ks.end());
    for(int i = 0; i < k; i++) {
        while(nidx < n && ns[nidx].first <= ks[i]) {
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
    solve();
    return 0;
}