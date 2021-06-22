#include <bits/stdc++.h>
using namespace std;
int n, l, ans, pre, w, s;
vector<pair<int, int>> v;
int main(void) {
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        // w = max(w, b);
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for(auto a: v) {
        if(pre < a.first) pre = a.first;
        while(pre < a.second) {
            // cout << "pre: " << pre << '\n';
            pre += l;
            ans += 1;
        }
    }
    cout << ans;
    return 0;
}
