#include <bits/stdc++.h>
using namespace std;
#define y1 qwerqewr
int n, m, a[1025][1025], x1, x2, y1, y2;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int t; cin >> t;
            a[i][j] = a[i][j - 1] + t;
        }
    }

    for(int i = 0; i < m; i++) {
        int sum = 0;
        cin >> y1 >> x1 >> y2 >> x2;
        for(int j = y1; j <= y2; j++) {
            sum += a[j][x2] - a[j][x1 - 1];
        }
        cout << sum << '\n';
    }
    return 0;
}