#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans;
vector<pair<ll, ll>> v;
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
    int l = v[0].first; int r = v[0].second;
    for(int i = 1; i < n; i++) {
        if(r < v[i].first) {
            ans += (r - l);
            l = v[i].first;
            r = v[i].second;
        } else if(r <= v[i].second) {
            r = v[i].second;
        }
    }
    ans += (r - l);
}
int main(void) {
    input();
    func();
    cout << ans;
    return 0;
}
// TODO: 꼭 다시 풀어봐야할 문제