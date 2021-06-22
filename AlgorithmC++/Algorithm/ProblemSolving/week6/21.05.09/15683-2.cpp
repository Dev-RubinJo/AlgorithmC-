#include <bits/stdc++.h>
using namespace std;

int a[8][8], n, m, ans = 987654321;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
bool tv[8];
vector<pair<int, int>> tvs;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] >= 1 && a[i][j] <= 5) tvs.push_back({i, j});
        }
    }
}

void check_area(int a, int y, int x, int d, int area[8][8]) {
    if(a == 1) {
        int nx = x + dx[d]; int ny = y + dy[d];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[d]; ny += dy[d];
        }
    } else if(a == 2)  {
        int nx = x + dx[d]; int ny = y + dy[d];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[d]; ny += dy[d];
        }
        nx = x + dx[(d + 2) % 4]; ny = y + dy[(d + 2) % 4];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[(d + 2) % 4]; ny += dy[(d + 2) % 4];
        }
    } else if(a == 3) {
        int nx = x + dx[d]; int ny = y + dy[d];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[d]; ny += dy[d];
        }
        nx = x + dx[(d + 1) % 4]; ny = y + dy[(d + 1) % 4];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[(d + 1) % 4]; ny += dy[(d + 1) % 4];
        }
    } else if(a == 4) {
        int nx = x + dx[d]; int ny = y + dy[d];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[d]; ny += dy[d];
        }
        nx = x + dx[(d + 1) % 4]; ny = y + dy[(d + 1) % 4];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[(d + 1) % 4]; ny += dy[(d + 1) % 4];
        }
        nx = x + dx[(d + 2) % 4]; ny = y + dy[(d + 2) % 4];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[(d + 2) % 4]; ny += dy[(d + 2) % 4];
        }
    } else if(a == 5) {
        int nx = x + dx[d]; int ny = y + dy[d];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[d]; ny += dy[d];
        }
        nx = x + dx[(d + 1) % 4]; ny = y + dy[(d + 1) % 4];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[(d + 1) % 4]; ny += dy[(d + 1) % 4];
        }
        nx = x + dx[(d + 2) % 4]; ny = y + dy[(d + 2) % 4];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[(d + 2) % 4]; ny += dy[(d + 2) % 4];
        }
        nx = x + dx[(d + 3) % 4]; ny = y + dy[(d + 3) % 4];
        while(area[ny][nx] != 6 && ny >= 0 && ny < n && nx >= 0 && nx < m) {
            area[ny][nx] = 9;
            nx += dx[(d + 3) % 4]; ny += dy[(d + 3) % 4];
        }
    }
}

void solve(int idx, int v[8][8]) {
    if(idx == tvs.size()) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!v[i][j]) sum += 1;
            }
        }
        // cout << '\n';
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << v[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        ans = min(ans, sum);
        return;
    }
    for(int i = 0; i < 4; i++) {
        int temp[8][8];
        for(int j = 0; j < n; j++) 
            for(int k = 0; k < m; k++) 
                temp[j][k] = v[j][k];
        check_area(a[tvs[idx].first][tvs[idx].second], tvs[idx].first, tvs[idx].second, i, temp);
        solve(idx + 1, temp);
    }
}

int main(void) {
    input();
    solve(0, a);
    cout << ans;
    return 0;
}