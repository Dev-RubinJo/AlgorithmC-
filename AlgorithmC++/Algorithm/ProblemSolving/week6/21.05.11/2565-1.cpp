#include <bits/stdc++.h>
using namespace std;
int n, ans, lis[101];
vector<pair<int, int>> v;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
}

void func() {
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(lis, lis + ans, v[i].second);
        if(!(*it)) ans += 1;
        *it = v[i].second;
    }
    cout << n - ans;
}

int main(void) {
    input();
    func();
    return 0;
}