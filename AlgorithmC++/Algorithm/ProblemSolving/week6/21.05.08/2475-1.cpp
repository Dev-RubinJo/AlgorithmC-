#include <bits/stdc++.h>
using namespace std;
int sum;

int main(void) {
    for(int i = 0; i < 5; i++) {
        int a; cin >> a;
        sum += pow(a, 2);
    }
    cout << sum % 10;
    return 0;
}