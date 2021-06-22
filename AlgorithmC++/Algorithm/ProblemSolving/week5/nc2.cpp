//
//  nc2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/22.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//
/*
#include <bits/stdc++.h>
using namespace std;
int n, visited[1004], e[1004][1004], a, b, ret1, ret2;
map<int, pair<int, int>> mp;
vector<int> adj[1004];
int go(int here){
    visited[here] = 1;
    int ret = 1;
    for(int there : adj[here]){
        if(visited[there]) continue;
        if(e[here][there]) continue;
        ret += go(there);
    }
    return ret;
}
bool check(){
    memset(visited, 0, sizeof(visited));
    vector<int> ret;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        if(visited[i] == 0) cnt += go(i);
        if(cnt) ret.push_back(cnt);
    }
    for(int a : ret){
        if(a != n / 3) return false;
    }
    return true;
}
void go(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            // 간선 2개를 지우는 코드
            pair<int, int> c = mp[i];
            pair<int, int> d = mp[j];
            e[c.first][c.second] = 1;
            e[c.second][c.first] = 1;
            e[d.first][d.second] = 1;
            e[d.second][d.first] = 1;
            // 탐색 해서 3개로 나눠졌는가 확인하는 코드
            ret1 = i + 1;
            ret2 = j + 1;
            if(check()) return;
            e[c.first][c.second] = 0;
            e[c.second][c.first] = 0;
            e[d.first][d.second] = 0;
            e[d.second][d.first] = 0;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        mp[i] = {a, b};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    go();
    cout << ret1 - 1<< "  " << ret2 - 1<< '\n';
    
    return 0;
}
 */
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int visited[101], e[101][101];
vector<int> answer;
vector<int> g[101];
map<int, pair<int, int>> edge;
int func(int idx) {
    int res = 1;
    visited[idx] = 1;
    for(int x: g[idx]) {
        if(visited[x]) continue;
        if(e[idx][x]) continue;
        res += func(x);
    }
    return res;
}
bool check(int n) {
    fill(visited, visited + 104, 0);
    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        res.push_back(func(i));
    }
    if(res.size() % 3) return false;
    for(int i = 0; i < res.size(); i++) {
        if(res[i] != n / 3) return false;
    }
    return true;
}
vector<int> solution(int n, vector<vector<int>> edges) {
    for(int i = 0; i < edges.size(); i++) {
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
        edge[i] = {edges[i][0], edges[i][1]};
    }
    for(int i = 0; i < edges.size(); i++) {
        for(int j = 0; j < i; j++) {
            pair<int, int> f = edge[i];
            pair<int, int> s = edge[j];
            e[f.first][f.second] = 1;
            e[f.second][f.first] = 1;
            e[s.first][s.second] = 1;
            e[s.second][s.first] = 1;
            if(check(n)) {
                answer.push_back(i);
                answer.push_back(j);
                sort(answer.begin(), answer.end());
                return answer;
            }
            e[f.first][f.second] = 0;
            e[f.second][f.first] = 0;
            e[s.first][s.second] = 0;
            e[s.second][s.first] = 0;
        }
    }
    return answer;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> answer = solution(9, {{0, 2}, {2, 1}, {2, 4}, {3, 5}, {5, 4}, {5, 7}, {7, 6}, {6, 8}});
    for(int a: answer) {
        cout << a << " ";
    }
    return 0;
}

 */

#include <string>
#include <iostream>
#include <vector>
using namespace std;

string solution(string sentence, string keyword, vector<int> skips) {
    int idx = 0, insertLen = 0;
    int sensize = sentence.size();
    for(int i = 0; i < skips.size(); i++) {
        if(skips[i] == 0) {
            sentence.insert(sentence.begin() + idx, keyword[i % keyword.size()]);
            idx += 1;
        } else {
            int flag = 0;
            for(int j = idx - 1; j < sentence.size(); j++) {
                if(j >= idx + skips[i]) break;
                if(sentence[j] == keyword[i % keyword.size()]) {
                    if(sentence.size() <= idx) {
                        sentence += string(1, keyword[i % keyword.size()]);
                        idx += 1;
                        break;
                    } else {
                        sentence.insert(sentence.begin() + j, keyword[i % keyword.size()]);
                        idx = j + 2;
                        flag = 1;
                        break;
                    }
                }
            }
            insertLen += skips[i];
            if(insertLen > sensize) break;
            if(!flag) {
                if(sentence.size() <= idx) {
                    sentence += string(1, keyword[i % keyword.size()]);
                    idx += 1;
                } else {
                    sentence.insert(sentence.begin() + idx + skips[i], keyword[i % keyword.size()]);
                    idx += skips[i] + 1;
                }
            }
        }

    }
    return sentence;
}

int main(void) {
    cout << solution("i love coding", "mask",  {0, 0, 3, 2, 3, 4}) << '\n';
    cout << solution("i love coding", "mode", {0, 10}) << '\n';
    cout << solution("abcde fghi", "xyz", {10, 0, 1}) << '\n';
    cout << solution("encrypt this sentence", "something", {0, 1, 3, 2, 1, 2, 0, 3, 0, 2, 4, 1, 3});
    return 0;
}
