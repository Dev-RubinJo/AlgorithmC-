#include <bits/stdc++.h>
using namespace std;
#define prev qwerqwer
int n, l, prev, ans;
vector<pair<int, int>> v;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        if(prev < v[i].first) prev = v[i].first;
        int j = 0;
        while(1) {
            if(prev + l * j >= v[i].second) break;
            j += 1;
        }
        prev += l * j;
        ans += j;
    }

    cout << ans;
    return 0;
}