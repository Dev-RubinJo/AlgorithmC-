#include <bits/stdc++.h>
using namespace std;
int n, m, a[100001];

int check(int num) {
    auto it = lower_bound(a, a + n, num);
    if(*it == num) return 1;
    else return 0;
}

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        cout << check(tmp) << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    return 0;
}