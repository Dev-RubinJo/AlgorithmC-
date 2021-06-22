#include <bits/stdc++.h>
using namespace std;
int n, k;
queue<int> q, ans;

void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
}

void func() {
    while(!q.empty()) {
        for(int i = 0; i < k - 1; i++) {
            int tmp = q.front(); q.pop();
            q.push(tmp);
        }
        ans.push(q.front()); q.pop();
    }
    cout << "<";
    while(ans.size() > 1) {
        cout << ans.front() << ", ";
        ans.pop();
    }
    cout << ans.front() << ">";
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func();
    return 0;
}