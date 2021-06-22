#include <bits/stdc++.h>
using namespace std;
int n, m, k, t, num[301], lack[301], dp[301][301];
vector<pair<int, int>> v;

void input() {
    cin >> n >> m >> k >> t;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        for(int j = a; j < b; j++) {
            num[j] += 1;
            num[j] = min(num[j], t);
        }
    }
}

int func(int idx, int cnt, int before) {
    if(idx == v.size()) return 0;
    int &res = dp[idx][cnt];
    if(res) return res;
    
    int fri = max(0, t - v[idx].second);
    int invite = (before >= fri) ? 0 : fri;

    if(cnt - invite >= 0) {
        return res = max(func(idx + 1, cnt - invite, fri) + v[idx].first, func(idx + 1, cnt, 0));
    } else {
        return res = func(idx + 1, cnt, 0);
    }
}

void solve() {
    int tmp = num[1];
    int cnt = 1;
    for(int i = 2; i <= n; i++) {
        if(tmp != num[i]) {
            v.push_back({cnt, tmp});
            cnt = 0;
            tmp = num[i];
        }
        cnt += 1;
    }
    v.push_back({cnt, tmp});

    cout << func(0, k, 0);
}

int main(void) {
    input();
    solve();
    return 0;
}