/*
처음에 이 문제를 봤을때 그리디라고 생각을 했다. 먼저 가장 큰 색종이를 붙여두고 나머지 공간에 대해서 다른 색종이들을 채워나가는 식으로 구성을 했는데 틀렸다.
미처 생각하지 못한 반례들이 있었던 것이다. 그래서 생각난 문제가 과거에 풀었던 쿼드트리 문제였다. 재귀적으로 색종이를 붙이는 것. 
하지만 아직 제대로 어떻게 풀어야할지 모르겠다.



처음에 그리디로 생각하고 풀었을 때의 반례
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
답은 6이다.
*/

#include <bits/stdc++.h>
using namespace std;
int ans = 987654321, cnt;
bool arr[11][11], visited[11][11], flag;
map<int, int> m1;
void input() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> arr[i][j];
            if(arr[i][j]) cnt += 1;
        }
    }
    for(int i = 0; i < 5; i++) {
        m1[5 - i] = 5;
    }
}

bool check(int y, int x, int n) {
    if(y + n > 10 || x + n > 10) return false;
    if(m1[n] == 0) return false;
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            if(!arr[i][j]) return false;
            // arr[i][j] = v;
        }
    }
    return true;
}

void fill(int y, int x, int n, int v) {
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            arr[i][j] = v;
        }
    }
}

void dfs(int y, int x, int cnt) {
    while(!arr[y][x]) {
        x += 1;
        if(x == 10) {
            y += 1;
            if(y == 10) {
                break;
            }
            x = 0;
        }
    }
    if(y == 10 && x == 10) {
        ans = min(ans, cnt);
        return;
    }

    for(int i = 0; i < 5; i++) {
        if(check(y, x, 5 - i)) {
            fill(y, x, 5 - i, 0);
            m1[5 - i] -= 1;
            dfs(y, x, cnt + 1);
            fill(y, x, 5 - i, 1);
            m1[5 - i] += 1;
        }
    }
}

int main(void) {
    input();
    dfs(0, 0, 0);
    if(ans == 987654321) cout << -1;
    else cout << ans;
    return 0;
}


/*
// MARK: 그리디로 생각하고 풀었던 풀이
#include <bits/stdc++.h>
using namespace std;
bool arr[11][11], flag, carr[11][11];
int ans, color[] = {5, 4, 3, 2, 1};
map<int, int> m1;
void input() {
    for(int i = 0; i < 10; i++) 
        for(int j = 0; j < 10; j++)
            cin >> arr[i][j];

    for(int i = 0; i < 5; i++) {
        m1[5 - i] = 5;
    }
}

bool check(int y, int x, int n) {
    if(y + n > 10 || x + n > 10) return false;
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            if(!arr[i][j]) return false;
        }
    }
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            arr[i][j] = 0;
        }
    }
    m1[n] -= 1;
    if(m1[n] < 0) flag = 1;
    return true;
}

void func() {
    int cnt = 0;
    for(int n = 0; n < 5; n++) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(arr[i][j]) {
                    if(check(i, j, color[n])) {
                        cnt += 1;
                        if(flag) break;
                    }
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(!flag) {
        ans = min(ans, cnt);
    } else {
        ans = -1;
    }
}


int main(void) {
    input();
    func();
    return 0;
}
*/