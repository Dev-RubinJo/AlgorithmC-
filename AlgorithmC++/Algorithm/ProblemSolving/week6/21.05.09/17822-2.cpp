#include <bits/stdc++.h>
using namespace std;

int n, m, t, ans;
vector<vector<int>> v;
int cmd[50][3];

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        vector<int> temp;
        for(int i = 0; i < m; i++) {
            int a; cin >> a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }

    for(int i = 0; i < t; i++) {
        cin >> cmd[i][0] >> cmd[i][1] >> cmd[i][2];
    }
}

void rotation(int idx, int d, int k) {
    if(d) rotate(v[idx].begin(), v[idx].begin() + k, v[idx].end());
    else rotate(v[idx].begin(), v[idx].begin() + v[idx].size() - k, v[idx].end());
}

void do_cmd(int idx) {
    for(int i = cmd[idx][0] - 1; i < n; i += cmd[idx][0]) {
        rotation(i, cmd[idx][1], cmd[idx][2]);
    }
}

void check(int y, int x, queue<pair<int, int>> &q) {
    int cur = v[y][x], lx, rx;
    int flag = 0;
    if(x == 0) {
        lx = m - 1;
        rx = x + 1;
    } else if(x == m - 1) {
        lx = x - 1;
        rx = 0;
    } else {
        lx = x - 1;
        rx = x + 1;
    }
    if(y == 0) {
        if(v[y][lx] == cur) {
            q.push({y, lx});
            flag = 1;
        } else if(v[y][rx] == cur) {
            q.push({y, rx});
            flag = 1;
        } else if(v[y + 1][x] == cur) {
            q.push({y + 1, x});
            flag = 1;
        }
    } else if(y == n - 1) {
        if(v[y][lx] == cur) {
            q.push({y, lx});
            flag = 1;
        } else if(v[y][rx] == cur) {
            q.push({y, rx});
            flag = 1;
        } else if(v[y - 1][x] == cur) {
            q.push({y - 1, x});
            flag = 1;
        }
    } else {
        if(v[y][lx] == cur) {
            q.push({y, lx});
            flag = 1;
        } else if(v[y][rx] == cur) {
            q.push({y, rx});
            flag = 1;
        } else if(v[y - 1][x] == cur) {
            q.push({y - 1, x});
            flag = 1;
        } else if(v[y + 1][x] == cur) {
            q.push({y + 1, x});
            flag = 1;
        }
    }
    if(flag) q.push({y, x});
}

void solve() {
    for(int i = 0; i < t; i++) {
        queue<pair<int, int>> q;
        do_cmd(i);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!v[i][j]) continue;
                check(i, j, q);
            }
        }
        if(q.empty()) {
            double sum = 0, cnt = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    sum += v[i][j];
                    if(v[i][j]) cnt += 1;   
                }
            }
            sum /= cnt;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(v[i][j]) {
                        if((double)v[i][j] < sum) v[i][j] += 1;
                        else if((double)v[i][j] > sum) v[i][j] -= 1;
                    }
                }
            }
        }
        while(!q.empty()) {
            int y = q.front().first, x = q.front().second; q.pop();
            v[y][x] = 0;
        }



        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << v[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans += v[i][j];
        }
    }
    cout << ans;
}

int main(void) {
    input();
    solve();
    return 0;
}