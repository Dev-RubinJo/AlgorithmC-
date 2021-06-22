#include <bits/stdc++.h>
using namespace std;

vector<deque<int>> v;

vector<int> solution(int n, vector<vector<int>> queries) {
    vector<int> answer;
    bool flag = 0;
    for(int i = 0; i < n; i++) {
        deque<int> tmp;
        if(queries[0][1] != -1) {
            tmp.push_back(queries[0][1]);
        } else {
            flag = 1;
        }
        v.push_back(tmp);
    }
    if(flag) {
        answer.push_back(-1);
    }

    for(int i = 1; i < queries.size(); i++) {
        if(queries[i][1] != -1) {
            v[queries[i][0] - 1].push_back(queries[i][1]);
        } else {
            if(v[queries[i][0] - 1].empty()) {
                answer.push_back(-1);
            } else {
                answer.push_back(v[queries[i][0] - 1].back());
                if(v[queries[i][0] - 1].size() == 1) {
                    for(int j = 0; j < n; j++) {
                        v[j].pop_front();
                    }
                    int cnt = 0;
                    int idx = (queries[i][0] + 1) % n;
                    while(cnt < n) {
                        if(v[idx].size() >= 1) break;
                        idx = (idx + 1) % n;
                        cnt += 1;
                    }
                    int value = v[idx].front();
                    cnt = 0;

                    while(cnt < n - 1) {
                        idx = (idx + 1) % n;
                        v[idx].push_front(value);
                        cnt += 1;
                    }
                } else {
                    v[queries[i][0] - 1].pop_back();
                }
            }
        }
    }
    return answer;
}