#include <bits/stdc++.h>
using namespace std;
int r, c, t, ans, m1[51][51], m2[51][51];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int ccw[] = {3, 0, 1, 2};
int cw[] = {3, 2, 1, 0};
vector<pair<int, int>> puri;
void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> m1[i][j];
            if(m1[i][j] == -1) puri.push_back({i, j});
        }
    }
}

void spread() {
    fill(&m2[0][0], &m2[0][0] + 51 * 51, 0);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(!m1[i][j]) continue;
            if(m1[i][j] == -1) {
                m2[i][j] = -1;
                continue;
            }
            vector<pair<int, int>> v;
            for(int k = 0; k < 4; k++) {
                int nx = j + dx[k]; int ny = i + dy[k];
                if(nx < 0 || ny < 0 || nx >= c || ny >= r || m1[ny][nx] == -1) continue;
                v.push_back({ny, nx});
            }
            int sp = m1[i][j] / 5;
            m2[i][j] += m1[i][j] - sp * v.size();
            for(auto a: v) 
                m2[a.first][a.second] += sp;
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            m1[i][j] = m2[i][j];
        }
    }
}

void purify(int y, int x, int d[]) {
    int cx = x + 1; int cy = y;
    m2[cy][cx] = 0;
    m2[y][x] = -1;
    for(int i = 0; i < 4; i++) {
        while(1) {
            int nx = cx + dx[d[i]]; int ny = cy + dy[d[i]];
            if(nx < 0 || ny < 0 || nx >= c || ny >= r) break;
            if(nx == x && ny == y) break;
            m2[ny][nx] = m1[cy][cx];
            cy = ny;
            cx = nx;
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            m1[i][j] = m2[i][j];
        }
    }
}

int main(void) {
    input();
    // cout << '\n';
    for(int i = 0; i < t; i++) {
        spread();
        purify(puri[0].first, puri[0].second, ccw);
        purify(puri[1].first, puri[1].second, cw);
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            ans += m1[i][j];
            // cout << m1[i][j] << " ";
        }
        // cout << '\n';
    }
    
    cout << ans + 2;
    return 0;
}
