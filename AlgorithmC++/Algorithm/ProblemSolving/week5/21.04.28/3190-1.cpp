#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, k, l, d, ans, flag;
deque<pii> snake;
queue<pair<int, char>> q;
int m[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void turn(char c) {
    if(c == 'L') {
        if(!d) d = 4;
        d = (d - 1) % 4;
    } else {
        d = (d + 1) % 4;
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        m[a][b] = 1;
    }
    cin >> l;
    for(int i = 0; i < l; i++) {
        int a; char c; cin >> a >> c;
        q.push({a, c});
    }
    snake.push_back({1, 1});
    int a; char c;
    tie(a, c) = q.front(); q.pop();
    while(1) {
        ans += 1;
        int cx, cy; tie(cy, cx) = snake.back();
        int ny = cy + dy[d]; int nx = cx + dx[d];
        // cout << ny << " : " << nx << '\n';
        auto it = find(snake.begin(), snake.end(), pii(ny, nx));
        if(nx <= 0 || nx > n || ny <= 0 || ny > n) { break; }
        if(it != snake.end()) { break; }
        snake.push_back(pii(ny, nx));
        if(!m[ny][nx]) snake.pop_front();
        else m[ny][nx] = 0;
        if(ans == a) {
            turn(c);
            tie(a, c) = q.front(); q.pop();
        }
    }
    cout << ans;
    return 0;
}