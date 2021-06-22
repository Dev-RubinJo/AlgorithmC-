//
//  14502-l.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/08.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
int n, m, virus[9][9], a[9][9], maxS, cnt;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
vector<pair<int, int> > safe;
void vir(int y, int x) {
    virus[y][x] = 2;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || virus[ny][nx] != 0) continue;
        vir(ny, nx);
    }
}
void solution() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            virus[i][j] = a[i][j];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(virus[i][j] == 2) vir(i, j);
        }
    }
    cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!virus[i][j]) {
                cnt += 1;
            }
        }
    }
    maxS = max(maxS, cnt);
}
int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(!a[i][j]) safe.push_back(make_pair(i, j));
        }
    }
    for(int i = 0; i < safe.size(); i++) {
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < j; k++) {
                a[safe[i].first][safe[i].second] = a[safe[j].first][safe[j].second] = a[safe[k].first][safe[k].second] = 1;
                solution();
                a[safe[i].first][safe[i].second] = a[safe[j].first][safe[j].second] = a[safe[k].first][safe[k].second] = 0;
            }
        }
    }
    cout << maxS;
    return 0;
}
