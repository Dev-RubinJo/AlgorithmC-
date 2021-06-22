#include <bits/stdc++.h>
using namespace std;
int n, x, ans;
vector<int> v;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    cin >> x;
}
void func() {
    sort(v.begin(), v.end());
    int l = 0; int r = v.size() - 1;
    while(l < r) {
        if(v[l] + v[r] < x)
            l += 1;
        else if(v[l] + v[r] > x)
            r -= 1;
        else {
            ans += 1;
            l += 1;
            r -= 1;
        }
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}