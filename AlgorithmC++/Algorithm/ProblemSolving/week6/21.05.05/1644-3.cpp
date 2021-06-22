#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans;
bool v[4000001];
vector<int> a;
void prime(int num) {
    for(ll i = 2; i <= num; i++) 
        v[i] = 1;
    for(ll i = 2; i <= num; i++) {
        if(!v[i]) continue;
        for(ll j = i * i; j <= num; j += i) 
            v[j] = 0;
    }
    for(int i = 2; i <= num; i++) 
        if(v[i]) a.push_back(i);
}

void solve() {
    int l = 0, r = 1;
    int sum = a[l];
    while(r <= a.size()) {
        if(sum + a[r] < n) {
            sum += a[r];
            r += 1;
        }  else if(sum + a[r] > n) {
            sum -= a[l];
            l += 1;
        } else {
            ans += 1;
            sum -= a[l];
            sum += a[r];
            l += 1;
            r += 1;
        }
    }
    cout << ans;
}

int main(void) {
    cin >> n;
    if(n == 1) cout << 0;
    else {
        prime(n);
        solve();
    }
    return 0;
}
