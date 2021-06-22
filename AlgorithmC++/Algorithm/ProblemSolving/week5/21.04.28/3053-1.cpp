#include <bits/stdc++.h>
#define PI 3.1415926535897932
using namespace std;
long double r;
int main() {
    cin >> r;
    cout << fixed;
    cout.precision(6);
    cout << powl(r, 2) * PI << '\n';
    cout << powl(r, 2) * 2 << '\n';
    return 0;
}