#include <bits/stdc++.h>
using namespace std;
int tc, n, m, a[1000001], b[1000001];

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) 
        cin >> b[i];
    sort(a, a + n);
}

int bisearch(int x) {
    int l = 0, r = n - 1, flag = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] > x) { r = mid - 1; }
        else if(a[mid] < x) { l = mid + 1; }
        else { flag = 1; break; }
    }
    if(flag) return 1;
    else return 0;
}

void solve() {
    for(int i = 0; i < m; i++) {
        cout << bisearch(b[i]) << '\n';
    }
}

void func() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc) {
        input();
        solve();
        tc -= 1;
    }
}

int main(void) {
    func();
    return 0;
}