//
//  1339.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, cnt, a[26], ans;
bool vi[10];
string s;
vector<string> v;
void input() {
    fill(a, a + 26, -1);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < s.size(); j++)
            a[s[j] - 'A'] = -2;
        v.push_back(s);
    }
    for(int i = 0; i < 26; i++)
        if(a[i] != -1) cnt += 1;
}
void func(int idx, int c, int num) {
    if(idx == 26 || c == cnt) {
        int sum = 0;
        for(int i = 0; i < v.size(); i++) {
            int cur = 0;
            for(int j = v[i].size() - 1; j >= 0; j--) {
                cur = cur * 10 + a[v[i][j] - 'A'];
            }
            sum += cur;
        }
        ans = max(sum, ans);
        return;
    }
    for(int i = idx; i < 26; i++) {
        if(a[i] == -1) continue;
        if(a[i] == -2) {
            for(int j = num; j < 10; j++) {
                if(vi[j]) continue;
                a[i] = j;
                vi[j] = 1;
                func(i + 1, c + 1, num + 1);
                a[i] = -2;
                vi[j] = 0;
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    func(0, 0, 0);
    cout << ans;
    return 0;
}
