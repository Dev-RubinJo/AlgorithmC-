#include <bits/stdc++.h>
using namespace std;
int n, ans;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({b, a});
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first > b.first && a.second < b.second) return true;
    return false;
}

int main(void) {
    input();
    sort(v.begin(), v.end());
    // cout << '\n';
    // for(auto vv: v) cout << vv.first << " : " << vv.second << '\n';
    for(int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if(pq.size() > v[i].first) pq.pop();
        
    }
    while(!pq.empty()) { ans += pq.top(); pq.pop(); }
    cout << ans;
    return 0;
}