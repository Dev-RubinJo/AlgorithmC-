#include <bits/stdc++.h>
using namespace std;
int n, m, psum[100001];

void solve() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        psum[i] = psum[i - 1] + a;
    }
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cout << psum[b] - psum[a - 1] << '\n';
    }
}
int main(void) {
    solve();
    return 0;
}