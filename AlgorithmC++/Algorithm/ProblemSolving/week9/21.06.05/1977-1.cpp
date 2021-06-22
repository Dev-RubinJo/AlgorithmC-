#include <bits/stdc++.h>
using namespace std;
int n, m, ans, min_value = INT_MAX;
bool arr[10001];

void setup() {
    for(int i = 1; i <= 100; i++) {
        arr[i * i] = 1;
    }
}

void input() {
    cin >> m >> n;
}

void func() {
    for(int i = m; i <= n; i++) {
        if(arr[i]) {
            ans += i;
            min_value = min(min_value, i);
        } 
    }

    if(ans) {
        cout << ans << '\n' << min_value;
    } else {
        cout << -1;
    }
}

int main(void) {
    setup();
    input();
    func();
    return 0;
}