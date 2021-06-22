//
//  14620-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/12.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, m1[11][11], flower[11][11], visited[11][11], minCost = 987654321, total, cnt;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void dfs() {
    if(cnt == 3) {
        total = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(flower[i][j]) total += m1[i][j];
            }
        }
        minCost = min(minCost, total);
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1) continue;
            if(flower[i][j] || flower[i - 1][j] || flower[i][j - 1] || flower[i][j + 1] || flower[i + 1][j]) continue;
            flower[i][j] = flower[i - 1][j] = flower[i][j - 1] = flower[i][j + 1] = flower[i + 1][j] = 1;
            cnt += 1;
            dfs();
            flower[i][j] = flower[i - 1][j] = flower[i][j - 1] = flower[i][j + 1] = flower[i + 1][j] = 0;
            cnt -= 1;
        }   
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m1[i][j];
        }
    }
    dfs();
    cout << minCost;
    return 0;
}
/*
 #include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define endl '\n'
 int n, m1[11][11], flower[11][11], visited[11][11], minCost = 987654321, total, cnt;
 int dx[] = {0, -1, 0, 1};
 int dy[] = {-1, 0, 1, 0};
 void dfs(int y, int x) {
     if(cnt == 3) {
         total = 0;
         for(int i = 0; i < n; i++) {
             for(int j = 0; j < n; j++) {
                 if(flower[i][j]) total += m1[i][j];
             }
         }
         minCost = min(minCost, total);
         return;
     }
     for(int i = 0; i < 4; i++) {
         int nx = x + dx[i]; int ny = y + dy[i];
         if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx]) continue;
         if(flower[ny][nx] || flower[ny - 1][nx] || flower[ny][nx - 1] || flower[ny][nx + 1] || flower[ny + 1][nx]) continue;
         visited[ny][nx] = 1;
         if(nx == 0 || nx == n - 1 || ny == 0 || ny == n - 1) dfs(ny, nx);
         flower[ny][nx] = flower[ny - 1][nx] = flower[ny][nx - 1] = flower[ny][nx + 1] = flower[ny + 1][nx] = 1;
         cnt += 1;
         dfs(ny - 2, nx);
         flower[ny][nx] = flower[ny - 1][nx] = flower[ny][nx - 1] = flower[ny][nx + 1] = flower[ny + 1][nx] = 0;
         cnt -= 1;
         flower[ny][nx] = flower[ny - 1][nx] = flower[ny][nx - 1] = flower[ny][nx + 1] = flower[ny + 1][nx] = 1;
         cnt += 1;
         dfs(ny, nx - 2);
         flower[ny][nx] = flower[ny - 1][nx] = flower[ny][nx - 1] = flower[ny][nx + 1] = flower[ny + 1][nx] = 0;
         cnt -= 1;
         flower[ny][nx] = flower[ny - 1][nx] = flower[ny][nx - 1] = flower[ny][nx + 1] = flower[ny + 1][nx] = 1;
         cnt += 1;
         dfs(ny + 2, nx);
         flower[ny][nx] = flower[ny - 1][nx] = flower[ny][nx - 1] = flower[ny][nx + 1] = flower[ny + 1][nx] = 0;
         cnt -= 1;
         flower[ny][nx] = flower[ny - 1][nx] = flower[ny][nx - 1] = flower[ny][nx + 1] = flower[ny + 1][nx] = 1;
         cnt += 1;
         dfs(ny, nx + 2);
         flower[ny][nx] = flower[ny - 1][nx] = flower[ny][nx - 1] = flower[ny][nx + 1] = flower[ny + 1][nx] = 0;
         cnt -= 1;
     }
 }
 int main(void) {
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cin >> n;
     for(int i = 0; i < n; i++) {
         for(int j = 0; j < n; j++) {
             cin >> m1[i][j];
         }
     }
     dfs(0, 0);
     cout << minCost;
     return 0;
 }

 */
