//
//  1062-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/15.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, k, a[26], ans, total;
//vector<set<char>> v1;
vector<string> v1;
string s;
int checkCnt() {
    int cnt = 0, flag = 0;
    for(auto st: v1) {
        flag = 1;
        for(int i = 0; i < st.size(); i++) {
            if(!a[st[i] - 'a']) {
                flag = 0;
                break;
            }
        }
        if(flag) cnt += 1;
    }
    return cnt;
}
void go(int idx, int cnt) {
    if(cnt == k) {
        ans = max(ans, checkCnt());
        return;
    }
    for(int i = idx; i < 26; i++) {
        if(a[i]) continue;
        a[i] = 1;
        go(i, cnt + 1);
        a[i] = 0;
    }
    return;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> s;
        v1.push_back(s);
    }
    a['a' - 'a'] = 1;
    a['c' - 'a'] = 1;
    a['i' - 'a'] = 1;
    a['n' - 'a'] = 1;
    a['t' - 'a'] = 1;
    k -= 5;
    if(k < 0) cout << 0;
    else {
        go(0, 0);
        cout << ans;
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, k, ans, alpha[26], cnt;
vector<set<char>> v1;
string s;
void func() {
    for(int i = 0; i < k; i++) alpha[i] = 1;
    sort(alpha, alpha + 26);
    do {
        cnt = 0;
        for(auto st: v1) {
            int flag = 0;
            set<char> temp = st;
            for(int i = 0; i < 26; i++) {
                if(alpha[i]) {
                    char t = (char)(i + 'a');
                    auto it = temp.find(t);
                    if(it == temp.end()) {
                        flag = 1;
                        break;
                    } else {
                        temp.erase(it);
                    }
                }
            }
            if(flag || !temp.empty()) continue;
            cnt += 1;
        }
        ans = max(cnt, ans);
    } while(next_permutation(alpha, alpha + 26));
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> s;
        set<char> st;
        for(int j = 0; j < s.size(); j++) {
            st.insert(s[j]);
        }
        v1.push_back(st);
    }
    func();
    cout << ans;
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n, k, ans, alpha[26], cnt;
vector<set<char>> v1;
string s;
void func(int idx, int cur) {
    if(idx == v1.size()) {
        ans = max(cnt, ans);
        return;
    }
    int flag = 0, addCnt = 0;
    for(char c: v1[idx]) {
        if(!alpha[c - 'a']) {
            addCnt += 1;
            alpha[c - 'a'] += 1;
        } else
            alpha[c - 'a'] += 1;
        if(cur + addCnt > k)
            flag = 1;
    }
    if(flag) {
        for(char c: v1[idx]){
            alpha[c - 'a'] -= 1;
        }
        addCnt = 0;
    } else {
        cnt += 1;
    }
    func(idx + 1, cur + addCnt);
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> s;
        set<char> st;
        for(int j = 0; j < s.size(); j++) {
            st.insert(s[j]);
        }
        v1.push_back(st);
    }
    func(0, 0);
    cout << ans;
    return 0;
}
*/
