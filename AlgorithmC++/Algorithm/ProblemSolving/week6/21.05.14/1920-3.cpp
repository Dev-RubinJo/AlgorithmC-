#include <bits/stdc++.h>
using namespace std;
int n, m, a[100001], tmp;

bool check(int tmp) {
    int lo = 0, hi = n;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(a[mid] == tmp) return true;
        else if(a[mid] > tmp) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return false;
}

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        if(check(tmp)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    return 0;
}