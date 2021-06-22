/*
이 문제를 보고 처음에 시뮬레이션 문제라고 생각했다. 우선 이 문제의 시간제한은 0.3초, 매우 짧은 시간이다. 
하지만 입력 범위도 매우 작은 숫자가 들어오기에 시뮬레이션, 완전탐색으로 가능하다고 생각하여 우선 그렇게 구현을 해보았다.
*/

#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[11][11], g[11][11], ans;
vector<int> m1[11][11];
vector<int> death[11][11];
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void input() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            g[i][j] = 5;
        }
    }
    for(int i = 0; i < m; i++) {
        int y, x, z; cin >> y >> x >> z;
        m1[y - 1][x - 1].push_back(z);
    }
}

void spring() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!m1[i][j].empty()) {
                sort(m1[i][j].begin(), m1[i][j].end());
                for(int k = 0; k < m1[i][j].size(); k++) {
                    if(g[i][j] >= m1[i][j][k]) {
                        g[i][j] -= m1[i][j][k];
                        m1[i][j][k] += 1;
                    } else {
                        death[i][j].push_back(m1[i][j][k]);
                        m1[i][j].erase(m1[i][j].begin() + k);
                        k -= 1;
                    }
                }
            }
        }
    }
}

void summer() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!death[i][j].empty()) {
                for(int d: death[i][j]) {
                    g[i][j] += d / 2;
                }
                death[i][j] = vector<int>();
            }
        }
    }
}

void fall() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!m1[i][j].empty()) {
                for(int tree: m1[i][j]) {
                    if(tree % 5 == 0) {
                        for(int k = 0; k < 8; k++) {
                            int nx = j + dx[k]; int ny = i + dy[k];
                            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                            m1[ny][nx].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void winter() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            g[i][j] += a[i][j];
        }
    }
}

void func() {
    for(int i = 0; i < k; i++) {
        spring();
        summer();
        fall();
        winter();
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += m1[i][j].size();
        }
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}