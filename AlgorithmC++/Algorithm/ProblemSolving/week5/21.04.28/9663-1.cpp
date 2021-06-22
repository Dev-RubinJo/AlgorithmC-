#include <bits/stdc++.h>
using namespace std;
int n, ans;
bool v[16][16];
bool check(int y, int x) {
    // 상
    int cy = y, cx = x;
    while(cy - 1 >= 0) {
        cy -= 1;
        if(v[cy][cx]) return false;
    }
    // 대각선 상 왼
    cy = y; cx = x;
    while(cy - 1 >= 0 && cx - 1 >= 0) {
        cy -= 1; cx -= 1;
        if(v[cy][cx]) return false;
    }
    // 대각선 상 오
    cy = y; cx = x;
    while(cy - 1 >= 0 && cx + 1 < n) {
        cy -= 1; cx += 1;
        if(v[cy][cx]) return false;
    }
    // // 대각선 하 왼
    // cy = y; cx = x;
    // while(cy + 1 < n && cx - 1 >= 0) {
    //     cy += 1; cx -= 1;
    //     if(v[cy][cx]) return false;
    // }
    // // 대각선 하 오
    // cy = y; cx = x;
    // while(cy + 1 < n && cx + 1 < n) {
    //     cy += 1; cx += 1;
    //     if(v[cy][cx]) return false;
    // }
    // // 하
    // cy = y; cx = x;
    // while(cy + 1 < n) {
    //     cy += 1;
    //     if(v[cy][cx]) return false;
    // }
    return true;
}
void func(int y) {
    if(y == n) {
        ans += 1;
        return;
    }
    for(int j = 0; j < n; j++) {
        if(check(y, j)) {
            v[y][j] = 1;
            func(y + 1);
            v[y][j] = 0;
        }
    }
    return;
}
int main(void) {
    cin >> n;
    func(0);
    cout << ans << '\n';
    return 0;
}