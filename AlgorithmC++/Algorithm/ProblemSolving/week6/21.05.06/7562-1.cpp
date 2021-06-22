#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int tc, l, v[301][301];
int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};

int bfs(queue<pii> &q, pii e) {
    while(!q.empty()) {
        int y, x; tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 8; i++) {
            int ny = y + dy[i]; int nx = x + dx[i];
            if(nx < 0 || nx >= l || ny < 0 || ny >= l || v[ny][nx]) continue;
            v[ny][nx] = v[y][x] + 1;
            if(ny == e.first && nx == e.second) {
                return v[ny][nx];
            }
            q.push({ny, nx});
        }
    }
    return v[e.first][e.second];
}

void solve(pii s, pii e) {
    queue<pii> q;
    fill(&v[0][0], &v[0][0] + 301 * 301, 0);
    q.push(s);
    v[s.first][s.second] = 1;
    cout << bfs(q, e) - 1 << '\n';
}

void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        int sy, sx, ey, ex;
        cin >> l;
        cin >> sy >> sx >> ey >> ex;
        solve(pii(sy, sx), pii(ey, ex));
    }
}

int main(void) {
    input();
    return 0;
}