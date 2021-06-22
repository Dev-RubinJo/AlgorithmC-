#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[100001], cnt[100001], s, e;
ll ans;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    while(e < n) {
        // cout << "s: " << s << " e: " <<  e << '\n';
        if(!cnt[a[e]]) {
            cnt[a[e]] += 1;
            e += 1;
        } else {
            ans += e - s;
            cnt[a[s]] -= 1;
            s += 1;
        }
    }
    ans += (e - s) * (e - s + 1) / 2;
    cout << ans;
    return 0;
}