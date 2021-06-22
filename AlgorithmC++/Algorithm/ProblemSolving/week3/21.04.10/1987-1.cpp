//
//  1987-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/10.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int r, c, maxH;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char ch[21][21];
set<pair<pair<int, int>, string>> q;
void bfs() {
    while(!q.empty()) {
        int y, x; string s;
        tie(y, x) = q.begin()->first; s = q.begin()->second; q.erase(q.begin());
        int size = s.size();
        maxH = max(maxH, size);
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) continue; // MARK: 처음에 nx 범위를 nx > c로 해서 틀림, 범위 실수 주의하자!
            auto it = s.find(ch[ny][nx]);
            if(it != string::npos) continue;
            q.insert(make_pair(make_pair(ny, nx), s + string(1, ch[ny][nx])));
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) cin >> ch[i][j];
    q.insert(make_pair(make_pair(0, 0), string(1, ch[0][0])));
    bfs();
    cout << maxH;
    return 0;
}
