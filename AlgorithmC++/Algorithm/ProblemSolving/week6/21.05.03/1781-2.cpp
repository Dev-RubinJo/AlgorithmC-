#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pil;
ll n, ans;
priority_queue<ll, vector<ll>, greater<ll>> pq;
vector<pil> v;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
}
void func() {
    for(int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if(pq.size() > v[i].first) pq.pop();
    }
    while(!pq.empty()) {
        ans += pq.top(); pq.pop();
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}
