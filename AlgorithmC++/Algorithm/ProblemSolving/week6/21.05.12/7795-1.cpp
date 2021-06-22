#include <bits/stdc++.h>
using namespace std;
int tc, n, m;
vector<int> a, b;

void func() {
    int ans = 0, minIdx = -1;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int aTemp: a) {
        int lo = 0, hi = b.size() - 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(aTemp > b[mid]) lo = mid + 1;
            else hi = mid - 1;
            
        }
        ans += lo;
    }
    cout << ans << '\n';
}

void input() {
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> n >> m;
        a.clear(); b.clear();
        for(int i = 0; i < n; i++) {
            int temp; cin >> temp;
            a.push_back(temp);
        }
        for(int i = 0; i < m; i++) {
            int temp; cin >> temp;
            b.push_back(temp);
        }
        func();
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;
int tc, n, m;
vector<int> a, b;

void func() {
    int ans = 0, minIdx = -1;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int aTemp: a) {
        int lo = 0, hi = b.size() - 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(aTemp > b[mid]) {
                lo += mid + 1;
                minIdx = mid;
            } else if(aTemp <= b[mid]) {
                hi = mid - 1;
            }
        }
        ans += minIdx + 1;
    }
    cout << ans << '\n';
}

void input() {
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> n >> m;
        a.clear(); b.clear();
        for(int i = 0; i < n; i++) {
            int temp; cin >> temp;
            a.push_back(temp);
        }
        for(int i = 0; i < m; i++) {
            int temp; cin >> temp;
            b.push_back(temp);
        }
        func();
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    return 0;
}

*/