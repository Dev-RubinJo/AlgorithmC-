#include <bits/stdc++.h>
using namespace std;

long long x, y, z, ans;

void input() {
    cin >> x >> y;
    z = (y * 100) / x;
}

void func() {
    long long cnt = 0, lo = 0, hi = x;
    while(lo <= hi) {
        cnt = (lo + hi) / 2;
        if((((y + cnt) * 100) / (x + cnt)) <= z) {
            lo = cnt + 1;
        } else {
            hi = cnt - 1;
            ans = cnt;
        }
    }
    cout << (ans ? ans : -1);
}

int main(void) {
    input();
    func();
    return 0;
}