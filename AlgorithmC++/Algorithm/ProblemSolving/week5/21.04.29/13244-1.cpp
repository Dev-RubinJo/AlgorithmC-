#include <bits/stdc++.h>
using namespace std;
int t, n, m;
bool v[1000001];
vector<int> a[1001];
bool func(int idx) {
    v[idx] = 1;
    int cnt = 0;
    for(int x: a[idx]) {
        if(v[x]) return false;
        auto it = find(a[x].begin(), a[x].end(), idx);
        if(it != a[x].end()) a[x].erase(it);
        func(x);
    }
    return true;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int tc = 0; tc < t; tc++) {
        int flag = 1;
        cin >> n >> m;
        fill(v, v + 1000001, 0);
        for(int i = 1; i <= n; i++) a[i].clear();
        for(int i = 0; i < m; i++) {
            int n1, n2; cin >> n1 >> n2;
            a[n1].push_back(n2);
            a[n2].push_back(n1);
        }
        if(m != n - 1) { cout << "graph\n"; continue; }
        flag = func(1);
        for(int i = 1; i <= n; i++) {
            if(v[i]) continue;
            else { flag = 0; break; }
        }
        if(!flag) cout << "graph\n";
        else cout << "tree\n";
    }
    return 0;
} 
// MARK: 사이클이 생기는 경우를 파악하는 법이 어떤게 있을까 생각을 해보자
