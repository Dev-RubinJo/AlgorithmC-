#include <bits/stdc++.h>
using namespace std;
int r, c, t, ans;
int m1[51][51], m2[51][51];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int ccw[] = {2, 0, 3, 1};
int cw[] = {2, 1, 3, 0};
vector<pair<int, int>> puri;
void input() {
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> m1[i][j];
            if(m1[i][j] == -1) {
                puri.push_back({i, j});
            }
        }
    }
}
void spread() {
    fill(&m2[0][0], &m2[0][0] + 51 * 51, 0);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(m1[i][j] == -1) {
                m2[i][j] = m1[i][j];
                continue;
            } else if (!m1[i][j]) continue;
            vector<pair<int, int>> v;
            for(int k = 0; k < 4; k++) {
                int nx = j + dx[k]; int ny = i + dy[k];
                if(nx < 0 || ny < 0 || nx >= c || ny >= r || m1[ny][nx] == -1) continue;
                v.push_back({ny, nx});
            }
            int sp = m1[i][j] / 5;
            for(auto a: v) {
                m2[a.first][a.second] += sp;
            }
            m2[i][j] += m1[i][j] - (sp * v.size());
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            m1[i][j] = m2[i][j];
        }
    }
}
void purifier(int cy, int cx, int d[]) {
    int y = cy; int x = cx + 1;
    m1[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        while(1) {
            int nx = x + dx[d[i]];
            int ny = y + dy[d[i]];
            if(nx < 0 || ny < 0 || nx >= c || ny >= r) break;
            if(cy == ny && cx == nx) break;
            m1[ny][nx] = m2[y][x];
            y = ny; x = nx;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    for(int i = 0; i < t; i++) {
        spread();
        purifier(puri[0].first, puri[0].second, ccw);
        purifier(puri[1].first, puri[1].second, cw);
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            ans += m1[i][j];
        }
    }
    cout << ans + 2;
    // spread();
    // cout << "\n";
    // for(int i = 0; i < r; i++) {
    //     for(int j = 0; j < c; j++) {
    //         cout << m1[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    // purifier(puri[0].first, puri[0].second, ccw);
    // purifier(puri[1].first, puri[1].second, cw);
    // for(int i = 0; i < r; i++) {
    //     for(int j = 0; j < c; j++) {
    //         cout << m1[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    return 0;
}
