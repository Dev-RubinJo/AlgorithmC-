#include <bits/stdc++.h>
using namespace std;
long long n, m, p;
int main(void) {
    while(1) {
        cin >> n >> m >> p;
        if(!n && !m && !p) break;
        if(n * n + m * m == p * p || n * n + p * p == m * m || m * m + p * p == n * n) cout << "right\n";
        else cout << "wrong\n";
    }
    return 0;
}
