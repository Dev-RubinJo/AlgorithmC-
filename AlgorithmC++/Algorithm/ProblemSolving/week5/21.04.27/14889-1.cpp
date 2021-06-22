#include <bits/stdc++.h>
using namespace std;
int n, a[21][21], ans = INT_MAX;
bool v[21];
int func2(int value) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i] == value && v[j] == value) {
                res += a[i][j];
            } 
        }
    }
    return res;
}
void func(int idx, int cnt) {
    if(cnt == n / 2) {
        int start = func2(0);
        int link = func2(1);
        ans = min(ans, abs(start - link));
        return;
    }
    for(int i = idx; i < n; i++) {
        if(v[i]) continue;
        v[i] = 1;
        func(i, cnt + 1);
        v[i] = 0;
    }
}
int main(void) {
    cin >> n; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    func(0, 0);
    cout << ans;
    return 0;
}