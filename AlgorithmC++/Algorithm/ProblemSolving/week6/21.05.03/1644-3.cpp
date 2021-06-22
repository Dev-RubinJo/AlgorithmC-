#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans;
vector<int> v;
bool nums[4000001];

void input() {
    cin >> n;
    for(int i = 2; i <= n; i++) {
        nums[i] = 1;
    }
    for(ll i = 2; i <= n; i++) {
        if(!nums[i]) continue;
        for(ll j = i * i; j <= n; j += i) {
            nums[j] = 0;
        }
    }
    for(int i = 0; i <= n; i++) {
        if(nums[i]) v.push_back(i);
    }
}
void func() {
    int l = 0, r = 1, sum = v[l] + v[r];
    while(r <= v.size()) {
        if(sum < n) {
            r += 1;
            sum += v[r];
        } else if(sum > n) {
            l += 1;
            sum -= v[l - 1];
        } else {
            // cout << l << " : " << v[l] << " : " << r << " : " << v[r] << '\n';
            ans += 1;
            r += 1;
            sum += v[r];
            l += 1;
            sum -= v[l - 1];
        }
    }
    cout << ans;
}

int main(void) {
    input();
    if(n == 1) cout << 0;
    else func();
    return 0;
}