#include <bits/stdc++.h>
using namespace std;
int n, ans;
bool m1[101][101];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};
vector<pair<pair<int, int>, pair<int, int>>> cmd;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int y, x, d, g; cin >> y >> x >> d >> g;
        cmd.push_back(make_pair(make_pair(y, x), make_pair(d, g)));
    }
}

// bool check(int y, int x) {
//     if(m1[y][x] && m1[y + 1][x] && m1[y][x + 1] && m1[y + 1][x + 1]) return true;
//     return false;
// }
void check(int y, int x) {
    if(y + 1 < 101 && x + 1 < 101) { //y - 1 >= 0 && x - 1 >= 0 && 
        if(m1[y][x] && m1[y + 1][x] && m1[y][x + 1] && m1[y + 1][x + 1]) {
            ans += 1;
        }
    }
}

void draw_curve(int idx) {
    int y = cmd[idx].first.first;
    int x = cmd[idx].first.second;
    int d = cmd[idx].second.first;
    int g = cmd[idx].second.second;
    vector<int> dir;
    dir.push_back(d);
    for(int i = 1; i <= g; i++) {
        int back_idx = dir.size() - 1;
        while(back_idx >= 0) {
            dir.push_back((dir[back_idx] + 1) % 4);
            back_idx -= 1;
        }
    }
    m1[y][x] = 1;
    for(int i = 0; i < dir.size(); i++) {
        int nx = x + dx[dir[i]]; int ny = y + dy[dir[i]];
        m1[ny][nx] = 1;
        x = nx; y = ny;
    }
}

void solve() {
    for(int i = 0; i < cmd.size(); i++) 
        draw_curve(i);
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            // if(check(i, j)) {
            //     ans += 1;
            // }
            check(i, j);
        }
    }
}

int main(void) {
    input();
    solve();

    // for(int i = 0; i < 10; i++) {
    //     for(int j = 0; j < 10; j++) {
    //         cout << m1[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << ans;
    return 0;
}