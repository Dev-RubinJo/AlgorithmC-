#include <bits/stdc++.h>
using namespace std;
int tc, n, m, tree[200002];
map<int, int> m1;

void update(int idx, int value) {
    while(idx <= 200002) {
        tree[idx] += value;
        idx += (idx & -idx);
    }
}

int sum(int idx) {
    int res = 0;
    while(idx > 0) {
        res += tree[idx];
        idx -= (idx & -idx);
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc) {
        cin >> n >> m;
        memset(tree, 0, sizeof(tree));
        m1.clear();
        int update_idx = 100001;
        for(int i = 1; i <= n; i++) {
            update(i + update_idx, 1);
            m1[i] = i + update_idx;
        }

        for(int i = 0; i < m; i++) {
            int tmp; cin >> tmp;
            int idx = m1[tmp];
            cout << sum(idx) - 1 << " ";
            update(idx, -1);
            update_idx -= 1;
            update(update_idx, 1);
            m1[tmp] = update_idx;
        }
        tc -= 1;
        cout << '\n';
    }
    return 0;
}