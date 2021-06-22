#include <bits/stdc++.h>
using namespace std;
int r, c, gr, gc, pr, pc;
int sy, sx;
bool isP;
string arr[101];
bool flag;

void input() {
    cin >> r >> c;
    cin >> gr >> gc >> pr >> pc;
    for(int i = 0; i < r; i++) {
        cin >> arr[i];
    }
}

void func() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(arr[i][j] == 'P') {
                sy = i; sx = j;
                isP = 1;
            }
            if(isP) break;
        }
        if(isP) break;
    }
    if(sy + pr <= r && sx + pc <= c) {
        for(int i = sy; i < sy + pr; i++) {
            for(int j = sx; j < sx + pc; j++) {
                if(arr[i][j] == 'G') {
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
    } else flag = 1;
    
    if(flag) cout << 1;
    else cout << 0;
}

int main(void) {
    input();
    func();
    return 0;
}