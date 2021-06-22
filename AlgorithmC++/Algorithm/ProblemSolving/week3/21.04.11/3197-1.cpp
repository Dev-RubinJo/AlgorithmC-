//
//  3197-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/11.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int r, c, cnt;
bool flag, sv[1501][1501], wv[1501][1501];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char m[1501][1501];
queue<pii> w, wt, s, st;
pii start;
pii wyx, syx;
void Qclear(queue<pair<int, int>> &q){
   queue<pair<int, int>> empty;
   swap(q,empty);
}
void swan() {
    while(!s.empty()) {
        syx = s.front(); s.pop();
        for(int i = 0; i < 4; i++) {
            int nx = syx.second + dx[i]; int ny = syx.first + dy[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r || sv[ny][nx]) continue;
            if(m[ny][nx] == 'L') { flag = 1; return; }
            if(m[ny][nx] == 'X') st.push(pii(ny, nx));
            else s.push(pii(ny, nx));
            sv[ny][nx] = 1; // MARK: 1) 이 조건
        }
    }
}
void melt() {
    while(!w.empty()) {
        wyx = w.front(); w.pop();
        for(int i = 0; i < 4; i++) {
            int nx = wyx.second + dx[i]; int ny = wyx.first + dy[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r || wv[ny][nx]) continue;
            if(m[ny][nx] == 'X') {
                m[ny][nx] = '.';
                wv[ny][nx] = 1; // MARK: 2) 이 조건이 있는 순서 때문에 메모리 초과로 틀림.
                wt.push(pii(ny, nx));
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> m[i][j];
            if(m[i][j] == '.') w.push(pii(i, j));
            else if(m[i][j] == 'L') {
                w.push(pii(i, j));
                start = pii(i, j);
            }
        }
    }
    s.push(start);
    sv[start.first][start.second] = 1;
    while(!flag) {
        swan();
        if(flag) break;
        melt();
        w = wt;
        s = st;
        Qclear(wt);
        Qclear(st);
        cnt += 1;
    }
    cout << cnt;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int r, c, a[1501][1501], cnt;
bool bvisited[1501][1501], flag;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
queue<pii> q;
queue<pii> swan;
queue<pii> tem;
queue<pii> stem;
pii v[2];
char temp;
void firstQueue() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(a[i][j] == 1) {
                for(int k = 0; k < 4; k++) {
                    int nx = j + dx[k]; int ny = i + dy[k];
                    if(nx < 0 || nx >= c || ny < 0 || ny >= r || a[ny][nx] == 1) continue;
                    q.push(pii(i, j));
                    break;
                }
            }
        }
    }
}
void bfs() {
    while(!swan.empty()) {
        int x, y;
        tie(y, x) = swan.front(); swan.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r || bvisited[ny][nx]) continue;
            if(ny == v[1].first &&  nx == v[1].second) {
                flag = 1;
                return;
            }
            if(a[ny][nx]) swan.push(pii(ny, nx));
            else stem.push(pii(ny, nx));
            bvisited[ny][nx] = 1;
        }
    }
}
void melt() {
    while(!q.empty()) {
        int x, y;
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r || a[ny][nx]) continue;
            a[ny][nx] = 1;
            tem.push(pii(ny, nx));
        }
        if(q.empty()) {
            cnt += 1;
            bfs();
            swan = stem;
            q = tem;
            stem = queue<pii>();
            tem = queue<pii>();
        }
        if(flag) break;
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int idx = 0;
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> temp;
            if(temp == '.' || temp == 'L') a[i][j] = 1;
            else a[i][j] = 0;
            if(temp == 'L') {
                v[idx] = pii(i, j);
                idx += 1;
            }
        }
    }
    firstQueue();
    bvisited[v[0].first][v[0].second] = 1;
    swan.push(v[0]);
    melt();
    cout << cnt;
    return 0;
}
*/
