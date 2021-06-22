//
//  14620-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/21.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, m[11][11], ans = INT_MAX;
bool visited[11][11];
void input() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m[i][j];
}
void dfs(int cnt) {
    if(cnt == 3) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j]) sum += m[i][j];
            }
        }
        ans = min(ans, sum);
        return;
    }
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < n - 1; j++) {
            if(visited[i][j] || visited[i - 1][j] || visited[i][j - 1] || visited[i + 1][j] || visited[i][j + 1]) continue;
            visited[i][j] = visited[i - 1][j] = visited[i][j - 1] = visited[i + 1][j] = visited[i][j + 1] = 1;
            dfs(cnt + 1);
            visited[i][j] = visited[i - 1][j] = visited[i][j - 1] = visited[i + 1][j] = visited[i][j + 1] = 0;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    dfs(0);
    cout << ans;
    return 0;
}
