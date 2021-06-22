#include <bits/stdc++.h>
using namespace std;
int tc, n, m, tree[200004], tmp; // 왜 200004일까
map<int, int> m1;

void update(int idx, int value) {
    while(idx <= 200004) {
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
        int updateIdx = 100001;
        for(int i = 1; i <= n; i++) {
            update(i + updateIdx, 1);
            m1[i] = i + updateIdx;
        }
        for(int i = 0; i < m; i++) {
            cin >> tmp;
            int idx = m1[tmp];
            cout << sum(idx) - 1 << " ";
            update(idx, -1);
            update(--updateIdx, 1);
            m1[tmp] = updateIdx;
        }
        tc -= 1;
        cout << '\n';
    }
    return 0;
}