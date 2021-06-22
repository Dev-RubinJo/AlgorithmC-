#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans = INT_MAX;
ll lo, hi;
vector<int> v;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++ ) {
        ll tmp; cin >> tmp;
        hi += tmp;
        lo = max(lo, tmp);
        v.push_back(tmp);
    }
}

void func() {
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll tmp = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(tmp + v[i] > mid) {
                tmp = 0;
                cnt += 1;
            }
            tmp += v[i];
        }
        cnt += 1;
        if(cnt > m) {
            lo = mid + 1;
        } else if(cnt <= m) {
            hi = mid - 1;
        }
    }

    cout << lo;
}

int main(void) {
    input();
    func();
    return 0;
}