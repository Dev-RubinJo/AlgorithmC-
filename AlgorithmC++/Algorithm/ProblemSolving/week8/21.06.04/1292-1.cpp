#include <bits/stdc++.h>
using namespace std;
int a, b, ans;
int arr[1001];

void setup() {
    int idx = 0;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 0; j < i; j++) {
            arr[idx] = i;
            idx += 1;
            if(idx > 1000) return;
        }
    }
}

void input() {
    cin >> a >> b;
}

void func() {
    for(int i = a - 1; i <= b - 1; i++) {
        ans += arr[i];
    }
    cout << ans;
}

int main(void) {
    setup();
    input();
    func();
    return 0;
}