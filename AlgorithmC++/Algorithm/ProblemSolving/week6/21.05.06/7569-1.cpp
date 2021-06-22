#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> pii;
int n, m, h, a[101][101][101], ans;
bool v[101][101][101], flag;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int dz[] = {-1, 1};
queue<pii> q;

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> h;
    for(int k = 0; k < h; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j][k];
                if(a[i][j][k] == 1) q.push(pii(i, j, k));
                else if(a[i][j][k] == -1) v[i][j][k] = 1;
            }
        }
    }
}

void bfs() {
    queue<pii> temp;
    while(!q.empty()) {
        int x, y, z; tie(y, x, z) = q.front(); q.pop();
        v[y][x][z] = 1;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i]; int nx = x + dx[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || v[ny][nx][z] || a[ny][nx][z]) continue;
            v[ny][nx][z] = 1;
            temp.push(pii(ny, nx, z));
        }
        for(int i = 0; i < 2; i++) {
            int nz = z + dz[i];
            if(nz < 0 || nz >= h || v[y][x][nz] || a[y][x][nz]) continue;
            v[y][x][nz] = 1;
            temp.push(pii(y, x, nz));
        }
        if(q.empty()) {
            ans += 1;
            q = temp;
            temp = queue<pii>();
        }
    }

    for(int k = 0; k < h; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                    if(!v[i][j][k]) {
                        flag = 1;
                        break;
                }
                if(flag) break;
            }
            if(flag) break;
        }
    }
    if(flag) {
        cout << -1 << '\n';
    } else {
        cout << ans - 1 << '\n';
    }
}

int main(void) {
    input();
    bfs();
    // for(int k = 0; k < h; k++) {
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < m; j++) {
    //             cout << v[i][j][k] << " ";
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}