#include <bits/stdc++.h>
using namespace std;
int v[6][6];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool check(vector<string> &place) {
    fill(&v[0][0], &v[0][0] + 6 * 6, 0);
    stack<pair<int, int>> st;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(place[i][j] == 'P') {
                st.push({i, j});
                v[i][j] = 1;
            }
        }
    }
    bool flag = 0;
    while(!st.empty()) {
        int x, y; tie(y, x) = st.top(); st.pop();
        int ox, oy;
        if(place[y][x] == 'P') { ox = x; oy = y; }
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || (v[ny][nx] != 1 && v[ny][nx]) || place[ny][nx] == 'X' || (ny == oy && nx == ox)) continue;
            if(place[ny][nx] == 'P' && v[y][x] <= 2) { flag = 1; break; }
            if(place[ny][nx] == 'P') continue;
            v[ny][nx] += v[y][x] + 1;
            st.push({ny, nx});
        }
        if(flag) break;
    }
    if(flag) return false;
    else return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i < places.size(); i++) {
        if(check(places[i])) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}

int main(void) {
    vector<int> ans = solution({{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
    {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
    {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
    {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
    {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});
    for(int a: ans) {
        cout << a << " ";
    }
    return 0;
}
