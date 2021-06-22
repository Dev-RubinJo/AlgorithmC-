#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans;
bool arr[1001][1001];

void fill() {
    for(int i = a; i < a + 10; i++) {
        for(int j = b; j < b + 10; j++) {
            arr[i][j] = 1;
        }
    }
}

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        fill();
    }
}

void func() {
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) {
            if(arr[i][j]) ans += 1;
        }
    }
    cout << ans;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func();
    return 0;
}