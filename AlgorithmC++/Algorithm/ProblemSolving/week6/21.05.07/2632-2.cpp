#include <bits/stdc++.h>
using namespace std;
int goal, m, n, ans;
int asum[2001], bsum[2001], a[1001], b[1001];
map<int, int> am, bm;
void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> goal;
    cin >> m >> n;
    for(int i = 0; i < m; i++) 
        cin >> a[i];
    for(int i = 0; i < n; i++) 
        cin >> b[i];
}

void solve() {
    for(int i = 1; i <= 2 * m; i++) 
        asum[i] = asum[i - 1] + a[(i - 1) % m];
    for(int i = 1; i <= 2 * n; i++) 
        bsum[i] = bsum[i - 1] + b[(i - 1) % n];
    
    for(int i = 1; i <= m; i++) {
        for(int j = i; j < m + i; j++) {
            am[asum[j]  - asum[j - i]] += 1;
            if(i == m) break;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i; j < n + i; j++) {
            bm[bsum[j]  - bsum[j - i]] += 1;
            if(i == n) break;
        }
    }

    for(int i = 1; i < goal; i++) {
        ans += am[i] * bm[goal - i];
    }
    ans += am[goal];
    ans += bm[goal];
    cout << ans;
}

int main(void) {
    input();
    solve();
    return 0;
}