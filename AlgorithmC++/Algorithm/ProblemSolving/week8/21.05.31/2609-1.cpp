#include <bits/stdc++.h>
using namespace std;
int a, b;

void input() {
    cin >> a >> b;
}

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
    cout << gcd(a, b) << '\n' << lcm(a, b);
}

int main(void) {
    input();
    func();
    return 0;
}