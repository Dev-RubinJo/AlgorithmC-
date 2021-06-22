#include <bits/stdc++.h>
using namespace std;
int n, ans = 1, pre;
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
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void func() {
    sort(v.begin(), v.end(), cmp);
    pre = v[0].second;
    for(int i = 1; i < n; i++) {
        if(v[i].first >= pre) {
            ans += 1;
            pre = v[i].second;
        }
    }

    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}