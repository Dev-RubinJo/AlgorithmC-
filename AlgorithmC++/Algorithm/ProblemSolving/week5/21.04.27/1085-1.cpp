#include <bits/stdc++.h>
using namespace std;
int x, y, h, w;
int ans;
int main(void) {
    cin >> x >> y >> w >> h;
    ans = ((x > y) ? y : x);
    ans = min(ans, w - x);
    ans = min(ans, h - y);
    cout << ans;
    return 0;
}
