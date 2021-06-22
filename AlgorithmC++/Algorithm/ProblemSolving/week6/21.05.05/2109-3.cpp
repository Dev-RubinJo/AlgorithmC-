#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({b, a});
    }
}

void solve() {
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if(pq.size() > v[i].first) {
            pq.pop();
        }
    }

    while(!pq.empty()) {
        ans += pq.top(); pq.pop();
    }

    cout << ans;
}

int main(void) {
    input();
    solve();
    return 0;
}