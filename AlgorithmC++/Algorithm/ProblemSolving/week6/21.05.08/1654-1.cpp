#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, n, a[10001];
int ans;
void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k >> n;
    for(int i = 0; i < k; i++)
        cin >> a[i];
}

void solve() {
    sort(a, a + k);
    ll lo = 1, hi = a[k - 1];
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        int tmp = 0;
        for(int i = 0; i < k; i++)
            tmp += (a[i] / mid);
        if(tmp < n)
            hi = mid - 1;
        else 
            lo = mid + 1;
    }
    ans = hi;
}

int main(void) {
    input();
    solve();
    cout << ans;
    return 0;
}