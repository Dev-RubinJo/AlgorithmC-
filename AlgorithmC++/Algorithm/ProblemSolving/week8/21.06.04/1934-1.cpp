#include <bits/stdc++.h>
using namespace std;
int tc, a, b;

int gcd(int a, int b) {
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void func() {
    cout << lcm(a, b) << '\n';
}

void input() {
    cin >> tc;
    while(tc) {
        tc -= 1;
        cin >> a >> b;
        func();
    }
}

int main(void) {
    input();
    return 0;
}