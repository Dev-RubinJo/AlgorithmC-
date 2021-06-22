#include <bits/stdc++.h>
using namespace std;
int n, m, d[100001], cur, t, lo, hi;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> d[i];
        t += d[i];
        lo = max(lo, d[i]); // 돈의 최소값을 이용해서 하는건줄 알았는데 보니까 최대값을 이용해야했다.
    }
}

void func() {
    hi = t;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        int cnt = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            if(sum + d[i] > mid) {
                cnt += 1;
                sum = 0;
            }
            sum += d[i];
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
    input();
    func();
    return 0;
}