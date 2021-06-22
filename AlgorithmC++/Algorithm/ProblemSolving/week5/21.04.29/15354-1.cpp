#include <bits/stdc++.h>
using namespace std;
int n, ans;
char pre = 'a';
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        char a; cin >> a;
        if(pre != a) {
            ans += 1;
            pre = a;
        }
    }
    cout << ans + 1;
    return 0;
}