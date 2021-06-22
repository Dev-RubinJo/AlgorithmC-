//
//  16234-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/09.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, l, r, ans;
int a[51][51], visited[51][51];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
queue<vector<pair<int, int>>> q;
void unionA(int y, int x) {
    vector<pair<int, int>> v;
    queue<pair<int, int>> qq;
    visited[y][x] = 1;
    qq.push(make_pair(y, x));
    v.push_back(make_pair(y, x));
    while(!qq.empty()) {
        int cx, cy;
        tie(cy, cx) = qq.front(); qq.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i]; int ny = cy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx]) continue;
            if(abs(a[cy][cx] - a[ny][nx]) >= l && abs(a[cy][cx] - a[ny][nx]) <= r) {
                visited[ny][nx] = 1;
                v.push_back(make_pair(ny, nx));
                qq.push(make_pair(ny, nx));
            }
        }
    }
    q.push(v);
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    while(1) {
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j])
                    unionA(i, j);
            }
        }
        if(q.size() == n * n) break;
        for(int i = 0; i < q.size(); i++) {
            vector<pair<int, int>> temp = q.front(); q.pop();
            int sum = 0;
            for(int j = 0; j < temp.size(); j++) {
                sum += a[temp[j].first][temp[j].second];
            }
            sum /= temp.size();
            for(int j = 0; j < temp.size(); j++) {
                a[temp[j].first][temp[j].second] = sum;
            }
            i -= 1;
        }
        ans += 1;
    }
    cout << ans;
    return 0;
}
