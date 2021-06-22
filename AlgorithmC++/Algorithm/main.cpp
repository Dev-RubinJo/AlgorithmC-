//
//  main.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/09.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<string> split(string s, string divid) {
    vector<string> v;
    char* c = strtok((char*)s.c_str(), divid.c_str());
    while (c) {
        v.push_back(c);
        c = strtok(NULL, divid.c_str());
    }
    return v;
}

bool v[101], ans[101], pro[11];
int lim, minimi = INT_MAX;
int lim_time, lim_space;
vector<vector<string>> datas;

void func(int idx, int cnt) {
    if(cnt == lim) {
        int ti = 0, sp = 0;
        for(int i = 0; i < datas.size(); i++) {
            if(v[i]) {
                ti += stoi(datas[i][2]);
                sp += stoi(datas[i][3]);
            }
        }
        if(ti <= lim_time && sp <= lim_space) {
            if(minimi > ti + sp) {
                minimi = ti + sp;
                for(int i = 0; i < datas.size(); i++) {
                    ans[i] = v[i];
                }
            }
        }
        return;
    }
    
    for(int i = idx; i < datas.size(); i++) {
        if(v[i]) continue;
        if(pro[datas[i][0][0] - 'a']) continue;
        v[i] = 1;
        pro[datas[i][0][0] - 'a'] = 1;
        func(idx, cnt + 1);
        v[i] = 0;
        pro[datas[i][0][0] - 'a'] = 0;
    }
}

vector<string> solution(int n, vector<string> data, string limit) {
    vector<string> answer;
    vector<string> limits = split(limit, " ");
    lim = n;
    for(string da: data) {
        datas.push_back(split(da, " "));
    }
    if(limits[0] == "0") {
        lim_time = INT_MAX;
    } else {
        lim_time = stoi(limits[0]);
    }
    if(limits[1] == "0") {
        lim_space = INT_MAX;
    } else {
        lim_space = stoi(limits[1]);
    }
    
    func(0, 0);
    
    for(int i = 0; i < datas.size(); i++) {
        if(ans[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
    
    return answer;
}

int main(void) {
    solution(2, {"a1 1 6 6", "a2 1 2 9", "b1 2 3 3", "b2 2 4 1"}, "0 0");
    return 0;
}
