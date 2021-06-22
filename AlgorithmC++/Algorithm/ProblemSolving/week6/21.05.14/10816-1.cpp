#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, tmp;
unordered_map<ll, int> m1;

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        m1[tmp] += 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        cout << m1[tmp] << " ";
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    return 0;
}