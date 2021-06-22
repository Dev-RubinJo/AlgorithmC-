//
//  nt2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/06.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100];
vector<int> solution(int n, vector<pair<int, int>> v) {
    vector<int> answer;
    for(int i = 0; i < v.size(); i++) {
        if(i % 2) {
            graph[v[i].first].push_back(v[i].second);
        } else {
            graph[v[i].second].push_back(v[i].first);
        }
    }
    return answer;
}
int main(void) {
    vector<pair<int, int>> v;
    v.push_back(make_pair(0, 2));
    v.push_back(make_pair(2, 1));
    v.push_back(make_pair(2, 4));
    v.push_back(make_pair(3, 5));
    v.push_back(make_pair(5, 4));
    v.push_back(make_pair(5, 7));
    v.push_back(make_pair(7, 6));
    v.push_back(make_pair(6, 8));
    auto asdf = solution(9, v);
    for(int i = 0; i < asdf.size(); i++) {
        cout << asdf[i] << '\n';
    }
    return 0;
}
