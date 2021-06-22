#include <bits/stdc++.h>
using namespace std;

void b(int a) {
    a = 2;
}

void b2(int &a) {
    a = 2;
}

void b3(int *a) {
    *a = 3;
}

int main() {

    int a = 1;
    b(a);
    cout << a << "\n";
    b3(&a);
    cout << a << "\n";
    b2(a);
    cout << a << "\n";
    b3(&a);
    cout << a << "\n";
    return 0;
}