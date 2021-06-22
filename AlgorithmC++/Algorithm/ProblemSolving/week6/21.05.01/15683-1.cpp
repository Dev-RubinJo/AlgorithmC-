#include <bits/stdc++.h>
using namespace std;
int n, m, ma[9][9], cnt, ans = INT_MAX;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
bool v[9][9];
vector<pair<int, int>> tv;
void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ma[i][j];
            if(ma[i][j] != 0 && ma[i][j] != 6) tv.push_back({i, j});
            if(ma[i][j]) v[i][j] = 1;
        }
    }
}
void cctv(int y, int x, int d, int cate, bool a[9][9]) {
    if(cate == 1) {
        int nx = x + dx[d]; int ny = y + dy[d];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[d]; ny += dy[d];
        }
    } else if(cate == 2) {
        int nx = x + dx[d]; int ny = y + dy[d];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[d]; ny += dy[d];
        }
        nx = x + dx[(d + 2) % 4]; ny = y + dy[(d + 2) % 4];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[(d + 2) % 4]; ny += dy[(d + 2) % 4];
        }
    } else if(cate == 3) {
        int nx = x + dx[d]; int ny = y + dy[d];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[d]; ny += dy[d];
        }
        nx = x + dx[(d + 1) % 4]; ny = y + dy[(d + 1) % 4];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[(d + 1) % 4]; ny += dy[(d + 1) % 4];
        }
    } else if(cate == 4) {
        int nx = x + dx[d]; int ny = y + dy[d];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[d]; ny += dy[d];
        }
        nx = x + dx[(d + 1) % 4]; ny = y + dy[(d + 1) % 4];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[(d + 1) % 4]; ny += dy[(d + 1) % 4];
        }
        nx = x + dx[(d + 2) % 4]; ny = y + dy[(d + 2) % 4];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[(d + 2) % 4]; ny += dy[(d + 2) % 4];
        }
    } else if(cate == 5) {
        int nx = x + dx[d]; int ny = y + dy[d];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[d]; ny += dy[d];
        }
        nx = x + dx[(d + 1) % 4]; ny = y + dy[(d + 1) % 4];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[(d + 1) % 4]; ny += dy[(d + 1) % 4];
        }
        nx = x + dx[(d + 2) % 4]; ny = y + dy[(d + 2) % 4];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[(d + 2) % 4]; ny += dy[(d + 2) % 4];
        }
        nx = x + dx[(d + 3) % 4]; ny = y + dy[(d + 3) % 4];
        while(nx >= 0 && ny >= 0 && nx < m && ny < n && ma[ny][nx] != 6) {
            a[ny][nx] = 1;
            nx += dx[(d + 3) % 4]; ny += dy[(d + 3) % 4];
        }
    }
}
int area(bool a[9][9]) {
    int res = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            if(!a[i][j]) res += 1;
    return res;
}
void func(int idx, bool a[9][9]) {
    if(idx == tv.size()) {
        ans = min(ans, area(a));
        return;
    }
    bool temp[9][9];
    for(int i = 0; i < 4; i++) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                temp[i][j] = a[i][j];
        cctv(tv[idx].first, tv[idx].second, i, ma[tv[idx].first][tv[idx].second], temp);
        func(idx + 1, temp);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                temp[i][j] = a[i][j];
    }
}

int main(void) {
    input();
    func(0, v);
    cout << ans;
    return 0;
}