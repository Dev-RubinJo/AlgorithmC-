#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int lesson[100001];

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> lesson[i];
        t += lesson[i];
    }
}

void func() {
    sort(lesson, lesson + n);
    int lo = lesson[n - 1], hi = t;
    while(lo <= hi) {
        // cout << "lo: " << lo << " hi: " << hi << '\n';
        int mid = (lo + hi) / 2;
        int sum = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(sum + lesson[i] > mid) {
                cnt += 1;
                sum = 0;
            }
            sum += lesson[i];
        }
        cnt += 1;
        if(cnt <= m) {
            hi = mid - 1;
        } else if(cnt > m) {
            lo = mid + 1;
        }
    }
    cout << lo;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func();
    return 0;
}