#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, ans;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int a[1001][1001];
bool v[1001][1001][2];

void input() {
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
}

int bfs() {
    queue<pair<pii, pii>> q; q.push(make_pair(pii(0, 0), pii(0, 1)));
    v[0][0][0] = 1;
    while(!q.empty()) {
        int y = q.front().first.first, x = q.front().first.second;
        int b = q.front().second.first, cnt= q.front().second.second; q.pop();

        if(y == n - 1 && x == m - 1) return cnt;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i]; int nx = x + dx[i];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if(a[ny][nx] == 1 && !b) {
                    v[ny][nx][b + 1] = 1;
                    q.push(make_pair(pii(ny, nx), pii(b + 1, cnt + 1)));
                }
                if(!a[ny][nx] && !v[ny][nx][b]) {
                    v[ny][nx][b] = 1;
                    q.push(make_pair(pii(ny, nx), pii(b, cnt + 1)));
                }
            }
        }
    }
    return -1;
}

int main(void) {
    input();
    ans = bfs();
    if(ans == -1) printf("-1");
    else printf("%d", ans);
    return 0;
}