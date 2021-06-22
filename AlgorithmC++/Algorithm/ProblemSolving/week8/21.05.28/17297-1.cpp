#include <bits/stdc++.h>
using namespace std;
string messi = "Messi Gimossi";
int m, fibo[40];

void input() {
    cin >> m;
    m -= 1;
}

void func() {
    fibo[0] = 0;
    fibo[1] = 5;
    fibo[2] = 13;

    for(int i = 3; i <= 40; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2] + 1;
        cout << "i: " << i << " : " << fibo[i] << '\n';
    }
    
    for(int i = 39; i >= 2; i--) {
        if(m >= fibo[i]) m -= (fibo[i]);
    }

    if(m == 5 || m == -1) cout << "Messi Messi Gimossi";
    else cout << messi[m];
}

int main(void) {
    input();
    func();
    return 0;
}