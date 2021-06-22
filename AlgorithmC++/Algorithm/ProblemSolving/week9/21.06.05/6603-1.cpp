#include <bits/stdc++.h>
using namespace std;
int k, arr[14];
bool v[50];

void func(int idx, int cnt) {
    if(cnt == 6) {
        for(int i = 0; i < 50; i++) {
            if(v[i]) cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = idx; i < k; i++) {
        if(v[arr[i]]) continue;
        v[arr[i]] = 1;
        func(i, cnt + 1);
        v[arr[i]] = 0;
    }
}

void input() {
    while(1) {
        cin >> k;
        if(!k) return;
        for(int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        func(0, 0);
        cout << '\n';
    }
}

int main(void) {
    input();
    return 0;
}