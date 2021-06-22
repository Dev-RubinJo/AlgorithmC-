#include <bits/stdc++.h>
using namespace std;
int n, k, a[101], v[101], ans;
vector<int> tap;
void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
}
void solve() {
    for(int i = 0; i < k; i++) {
        if(v[a[i]]) continue;
        if(tap.size() == n) {
            int idx = 0, pos;
            for(int t: tap) {
                int pick = INT_MAX;
                for(int j = i + 1; j < k; j++) {
                    if(t == a[j]) {
                        pick = j; break;
                    }
                }
                if(idx < pick) {
                    idx = pick;
                    pos = t;
                }
            }
            v[pos] = 0;
            ans += 1;
            tap.erase(find(tap.begin(), tap.end(), pos));
        }
        tap.push_back(a[i]); v[a[i]] = 1;
    }
    cout << ans;
}
int main(void) {
    input();
    solve();
    return 0;
}