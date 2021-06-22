//
//  2234-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/19.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, m, a[51][51], clan, cnt, max_value, total;
bool visited[51][51];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
pii area[51][51];
vector<pair<int, pii>> v;
void input() {
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
}
void dfs(int y, int x) {
    cnt += 1;
    for(int i = 1; i < (1 << 4); i *= 2) {
        if(!(i & a[y][x])) {
            int nx = 0, ny = 0;
            if(i == 1) {
                nx = x - 1; ny = y;
            } else if(i == 2) {
                nx = x ; ny = y - 1;
            } else if(i == 4) {
                nx = x + 1; ny = y;
            } else if(i == 8) {
                nx = x; ny = y + 1;
            }
            if(visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            v.push_back(make_pair(clan, pii(ny, nx)));
            dfs(ny, nx);
        }
    }
}
void func() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                cnt = 0;
                v.push_back(make_pair(clan, pii(i, j)));
                visited[i][j] = 1;
                dfs(i, j);
                for(int i = 0; i < v.size(); i++) {
                    area[v[i].second.first][v[i].second.second] = pii(clan, cnt);
                }
                v = vector<pair<int, pii>>();
                max_value = max(max_value, cnt);
                clan += 1;
            }
        }
    }
}
void func2() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 4; k++) {
                int ny = i + dy[k]; int nx = j + dx[k];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || area[i][j].first == area[ny][nx].first) continue;
                total = max(total, area[i][j].second + area[ny][nx].second);
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func();
    func2();
    cout << clan << endl;
    cout << max_value << endl;
    cout << total;
    return 0;
}
