#include <bits/stdc++.h>
using namespace std;
int n, k, ans, a[101], v[101];
vector<int> tab;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < k; i++) 
        cin >> a[i];
}

void func() {
    for(int i = 0; i < k; i++) {
        if(v[a[i]]) continue;
        if(tab.size() == n) {
            int idx = 0, pos;
            for(int t: tab) {
                int pick = INT_MAX;
                for(int j = i + 1; j < k; j++) {
                    if(t == a[j]) {
                        pick = j; break;
                    }
                }
                if(idx < pick) {
                    idx = pick;
                    pos = t;
                }
                cout << "t: " << t << " pick: " << pick << " idx: " << idx << " pos: " << pos << '\n';
            }
            v[pos] = 0;
            ans += 1;
            tab.erase(find(tab.begin(), tab.end(), pos));
        }
        tab.push_back(a[i]); v[a[i]] = 1;
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}