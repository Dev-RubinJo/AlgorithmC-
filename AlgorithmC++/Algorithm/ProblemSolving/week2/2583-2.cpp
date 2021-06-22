//
//  2583-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/02.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int a[101][101], m, n, tc, visited[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
vector<int> v;
void dfs(int y, int x) {
    tc += 1; // MARK: 먼저 최종 넓이를 구하는 변수에 1을 더한다.
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || a[ny][nx] || visited[ny][nx]) continue; // MARK: 여기에 visited 조건을 넣었으니 중복해서 넣지 않도록 하자
        dfs(ny, nx);
    }
}
int main(void) {
    cin >> m >> n >> tc;
    for(int t = 0; t < tc; t++) {
        int minx, miny, maxx, maxy;
        cin >> minx >> miny >> maxx >> maxy;
        for(int i = 0; i < maxy - miny; i++) {
            for(int j = 0; j < maxx - minx; j++) {
                a[miny + i][minx + j] = 1; // MARK: minx, miny에 각각 하나씩 올라가게끔 해서 그 칸을 1로 만든다
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!a[i][j] && !visited[i][j]) {
                tc = 0;
                dfs(i, j);
                v.push_back(tc);
            }
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}
