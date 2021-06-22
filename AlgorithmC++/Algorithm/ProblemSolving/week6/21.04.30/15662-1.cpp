#include <bits/stdc++.h>
using namespace std;
int t, k, ans;
vector<int> a[1001];
int cmd[1001][2];
void input() {
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        for(int j = 0; j < 8; j++) {
            int b; scanf("%1d", &b);
            a[i].push_back(b);
        }
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d%d", &cmd[i][0], &cmd[i][1]);
        cmd[i][0] -= 1;
    }
}
void check() {
    for(int i = 0; i < t; i++) {
        // for(int j: a[i]) cout << j << " ";
        // cout << '\n';
        if(a[i][0]) ans += 1;
    }
}
void rotate(int idx, int d) {
    if(!d) rotate(a[idx].begin(), a[idx].begin() + 1, a[idx].end());
    else rotate(a[idx].begin(), a[idx].begin() + a[idx].size() - 1, a[idx].end());
}
int left(int idx) {
    for(int i = idx; i >= 1; i--)
        if(a[i][6] == a[i - 1][2]) return i;
    return 0;
}
int right(int idx) {
    for(int i = idx; i <= t - 2; i++)
        if(a[i][2] == a[i + 1][6]) return i;
    return t - 1;
}
void exacute() {
    for(int i = 0; i < k; i++) {
        int d = (cmd[i][1] == -1 ? 0 : 1);
        int l = left(cmd[i][0]);
        int r = right(cmd[i][0]);
        int cnt = 0;
        for(int j = cmd[i][0]; j >= l; j--) {
            rotate(j, (cnt % 2 == 0 ? d : !d));
            cnt += 1;
        }
        cnt = 1;
        for(int j = cmd[i][0] + 1; j <= r; j++) {
            rotate(j, (cnt % 2 == 0 ? d : !d));
            cnt += 1;
        }
    }
}

int main(void) {
    input();
    exacute();
    check();
    cout << ans;
    return 0;
}
