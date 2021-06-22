#include <bits/stdc++.h>
using namespace std;
int n, arr[126][126], v[126][126];
const int INF = 987654321;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void func() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    v[0][0] = arr[0][0];
    while(!q.empty()) {
        int x, y; tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(v[ny][nx] > v[y][x] + arr[ny][nx]) {
                v[ny][nx] = v[y][x] + arr[ny][nx];
                q.push({ny, nx});
            }
        }
    }
    cout << v[n - 1][n - 1] << '\n';
}

void input() {
    int idx = 1;
    while(1) {
        cin >> n;
        if(!n) return;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        fill(&v[0][0], &v[0][0] + 126 * 126, INF);
        cout << "Problem " << idx << ": ";
        func();
        idx += 1;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    return 0;
}