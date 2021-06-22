#include <bits/stdc++.h>
using namespace std;
int aCnt, bCnt, ans;
map<int, int> m1;

void input() {
    cin >> aCnt >> bCnt;
    for(int i = 0; i < aCnt; i++) {
        int temp; cin >> temp;
        m1[temp] += 1;
    }
    for(int i = 0; i < bCnt; i++) {
        int temp; cin >> temp;
        m1[temp] += 1;
    }
}

void func() {
    for(auto it: m1) {
        if(it.second == 1) ans += 1;
    }
    cout << ans;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func();
    return 0;
}