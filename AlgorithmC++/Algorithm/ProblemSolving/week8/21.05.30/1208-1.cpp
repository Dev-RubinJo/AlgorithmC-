#include <bits/stdc++.h>
using namespace std;
int n, s, arr[41];
long long ans;
unordered_map<int, int> m1;

void input() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void divide(int idx, int end, int sum) {
    if(end != n) {
        if(idx == end) {
            m1[sum] += 1;
            return;
        }
    } else {
        if(idx == end) {
            ans += m1[s - sum];
            return;
        }
    }
    divide(idx + 1, end, sum);
    divide(idx + 1, end, sum + arr[idx]);
}

void func() {
    divide(0, n / 2, 0);
    divide(n / 2, n, 0);
    if(s == 0) ans -= 1;
    cout << ans;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func();
    return 0;
}