#include <bits/stdc++.h>
using namespace std;
int n, ans, d;
bool arr[17][17];
int dx[] = {1, 1, 0};
int dy[] = {0, 1, 1};

void input() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
}

void dfs(int y, int x, int d) {
    if(y == n - 1 && x == n - 1) {
        ans += 1;
        return;
    }
    int start = 0, end = 0;
    if(d == 0) {
        end = 2;
    } else if(d == 1) {
        end = 3;
    } else if(d == 2) {
        start = 1;
        end = 3;
    }
    for(int i = start; i < end; i++) {
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny >= n || nx >= n) continue;
        if(i == 1 && !arr[ny][nx] && !arr[y + 1][x] && !arr[y][x + 1]) {
            dfs(ny, nx, i);
        } else if(i != 1 && !arr[ny][nx]) {
            dfs(ny, nx, i);
        }
    }
}

void func() {
    dfs(0, 1, 0);
    // cout << visited[n - 1][n - 1];
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}