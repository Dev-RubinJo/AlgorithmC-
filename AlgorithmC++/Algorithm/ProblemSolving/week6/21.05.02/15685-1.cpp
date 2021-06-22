#include <bits/stdc++.h>
using namespace std;
int n, ans, x, y, d, g, end_x, end_y;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
bool v[101][101];
vector<int> dragon;

void make_gen(vector<int> &dragon) {
    int size = dragon.size();
    for(int i = size - 1; i >= 0; i--) {
        int dir = (dragon[i] + 1) % 4;
        end_x = end_x + dx[dir];
        end_y = end_y + dy[dir];

        v[end_y][end_x] = 1;
        dragon.push_back(dir);
    }
}

void check(int y, int x) {
    if(y + 1 < 101 && x + 1 < 101) { //y - 1 >= 0 && x - 1 >= 0 && 
        if(v[y][x] && v[y + 1][x] && v[y][x + 1] && v[y + 1][x + 1]) {
            ans += 1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        dragon.clear();
        v[y][x] = 1;
        end_x = x + dx[d];
        end_y = y + dy[d];
        v[end_y][end_x] = 1;
        dragon.push_back(d);
        for(int i = 0; i < g; i++) 
            make_gen(dragon);
    }
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            check(i, j);
        }
    }
    cout << ans;
    return 0;
}