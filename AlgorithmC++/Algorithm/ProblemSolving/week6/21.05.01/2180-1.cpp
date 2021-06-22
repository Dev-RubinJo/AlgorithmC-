#include <bits/stdc++.h>
using namespace std;
int n, ans, multi;
vector<pair<int, int>> v;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(b == make_pair(0, 0)) return false;
    if(a == make_pair(0, 0)) return true;
    if(a.second * b.first < b.second * a.first) return true;
    return false;
}

int main(void) {
    input();
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++) {
        ans = ((v[i].first + 1) * ans + v[i].second) % 40000;
    }
    cout << ans;
    return 0;
}