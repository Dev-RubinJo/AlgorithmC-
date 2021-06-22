//
//  13913-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/11.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int n, k, visited[100001], orders[100001], ti; // MARK: orders를 따로 생각해서 각 값이 오는 순서를 알아가는게 중요한 문제였다.
queue<pii> q;
void bfs() {
    while(!q.empty()) {
        int cur, t;
        tie(cur, t) = q.front(); q.pop();
        if(cur == k) {
            ti = t;
            cout << t << endl;
            return;
        }
        if(cur + 1 < 100001 && !visited[cur + 1]) {
            visited[cur + 1] = 1;
            orders[cur + 1] = cur;
            q.push(pii(cur + 1, t + 1));
        }
        if(cur - 1 >= 0 && !visited[cur - 1]) {
            visited[cur - 1] = 1;
            orders[cur - 1] = cur;
            q.push(pii(cur - 1, t + 1));
        }
        if(cur * 2 < 100001 && !visited[cur * 2]) {
            visited[cur * 2] = 1;
            orders[cur * 2] = cur;
            q.push(pii(cur * 2, t + 1));
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    q.push(pii(n, 0));
    bfs();
    vector<int> v;
    int idx = k;
    while(ti > 0) {
        ti -= 1;
        v.push_back(idx);
        idx = orders[idx];
    }
    v.push_back(n);
    reverse(v.rbegin(), v.rend());
    for(int a: v) cout << a << " ";
    return 0;
}
/*
 #include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 typedef pair<int, int> pii;
 #define endl '\n'
 int n, k, visited[100001], ti;
 queue<pii> q;
 queue<vector<int>> vq;
 vector<int> ans;
 void bfs() {
     while(!q.empty()) {
         int cur, t;
         tie(cur, t) = q.front(); q.pop();
         vector<int> v = vq.front(); vq.pop();
         if(cur == k) {
             ans = v;
             ti = t;
             return;
         }
         if(cur + 1 < 100001 && visited[cur + 1] > t) {
             visited[cur + 1] = t + 1;
             q.push(pii(cur + 1, t + 1));
             v.push_back(cur + 1);
             vq.push(v);
         }
         if(cur - 1 >= 0 && visited[cur - 1] > t) {
             visited[cur - 1] = t + 1;
             q.push(pii(cur - 1, t + 1));
             v.push_back(cur - 1);
             vq.push(v);
         }
         if(cur * 2 < 100001 && visited[cur * 2] > t) {
             visited[cur * 2] = t + 1;
             q.push(pii(cur * 2, t + 1));
             v.push_back(cur * 2);
             vq.push(v);
         }
     }
 }
 int main(void) {
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cin >> n >> k;
     fill(&visited[0], &visited[0] + 100001, 987654321);
     q.push(pii(n, 0));
     vq.push({n});
     bfs();
     return 0;
 }

 */
