#include <bits/stdc++.h>
using namespace std;
int n, m, t, ans;
int cmd[51][3];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
vector<int> a[51];
queue<pair<int, int>> q;
void input() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            int temp; cin >> temp;
            a[i].push_back(temp);
        }
    }
    for(int i = 0; i < t; i++) {
        cin >> cmd[i][0] >> cmd[i][1] >> cmd[i][2];
    }
}

void rotate(int idx, int d, int k) {
    if(d) rotate(a[idx].begin(), a[idx].begin() + k, a[idx].end()); // 반시계 방향 회전
    else rotate(a[idx].begin(), a[idx].begin() + a[idx].size() - k, a[idx].end()); // 시계 방향 회전
}

bool check(int y, int x) { // 인접하면서 같은 수가 있는 경우 false를 리턴.
    int flag = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(ny < 1 || ny > n) continue;
        if(nx == -1) nx = m - 1;
        else if(nx == m) nx = 0;
        if(a[ny][nx] == a[y][x] && a[y][x]) {
            q.push({ny, nx});
            flag = 1;
        }
    }
    if(flag) {
        a[y][x] = 0;
        return false;
    }
    return true;
}

void func(int idx, int d, int k) { // 회전 명령에 따른 회전 시키기
    int flag = 0;
    for(int i = idx; i <= n; i += idx)
        rotate(i, d, k);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            if(!check(i, j)) {
                flag = 1;
            }
        }
    }
    if(!flag) {
        double sum = 0; int cnt = 0;
        for(int i = 1; i <= n; i++) {
           for(int j = 0; j < m; j++) {
                sum += a[i][j];
                if(a[i][j]) cnt += 1;
            }
        }
        sum /= (double)cnt;
        for(int i = 1; i <= n; i++) {
           for(int j = 0; j < m; j++) {
                if(!a[i][j]) continue;
                if((double)a[i][j] > sum) a[i][j] -= 1;
                else if((double)a[i][j] < sum) a[i][j] += 1;
            }
        }
    } else {
        while(!q.empty()) {
            int y, x;
            tie(y, x) = q.front(); q.pop();
            a[y][x] = 0;
        }
    }
}

int main(void) {
    input();
    for(int i = 0; i < t; i++) {
        func(cmd[i][0], cmd[i][1], cmd[i][2]);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
        //    cout << a[i][j] << " ";
            ans += a[i][j];
        }
    //    cout << '\n';
    }
    cout << ans;
    return 0;
}
