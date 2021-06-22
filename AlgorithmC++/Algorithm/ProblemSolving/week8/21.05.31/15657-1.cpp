#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[9], ans[9];

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void back(int idx, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i < n; i++) {
        ans[cnt] = arr[i];
        back(i, cnt + 1);
    }
}

void func() {
    sort(arr, arr + n);
    back(0, 0);
}

int main(void) {
    input();
    func();
    return 0;
}