#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tc, n;
ll p[101];

void setup() {
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    for(int i = 4; i <= 100; i++) {
        p[i] = p[i - 2] + p[i - 3];
    }
}

void input() {
    cin >> tc;
    while(tc) {
        cin >> n; cout << p[n] << '\n';
        tc -= 1;
    }
}

int main(void) {
    setup();
    input();
    return 0;
}