#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_VALUE 60000000000
ll n, m, ans;
int arr[10001];

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> arr[i];
    }
}

void func() {
    ll lo = 0, hi = MAX_VALUE, total = 0;
    if(n <= m) {
        cout << n;
        return;
    }

    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll ride = m;
        for(int i = 1; i <= m; i++) {
            ride += mid / arr[i];
        }
        if(ride >= n) {
            total = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    ll ride = m;
    for(int i = 1; i <= m; i++) {
        ride += ((total - 1) / arr[i]);
    }

    for(int i = 1; i <= m; i++) {
        if(!(total % arr[i])) ride += 1;
        if(ride == n) {
            cout << i;
            return;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    input();
    func();
    return 0;
}