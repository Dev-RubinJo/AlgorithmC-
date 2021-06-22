#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans;
bool v[4000001];
void func() {
    for(ll i = 2; i <= n; i++) {
        v[i] = 1;
    }
    for(ll i = 2; i <= n; i ++) {
        if(!v[i]) continue;
        for(ll j = i * i; j <= n; j += i) {
            v[j] = 0;
        }
    }
}
int main(void) {
    cin >> n;
    func();
    for(ll i = 2; i <= n; i++) {
        if(!v[i]) continue;
        ll sum = 0;
        for(ll j = i; j <= n; j++) {
            if(!v[j]) continue;
            sum += j;
            if(sum == n) {
                ans += 1;
                break;
            } else if(sum > n) break;
        }
    }
    cout << ans;
    return 0;
}