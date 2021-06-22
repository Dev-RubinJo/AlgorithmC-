//
//  2910-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/02.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
map<int, int> m1, m2;
vector<pair<int, int> > v;
int n, c, temp, flag = 1;
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second) return m2[a.first] < m2[b.first]; // MARK: 빈도수가 같다면 m2 맵(나온 순서를 저장한 맵)에 있는 순서를 기준으로 먼저 나온게 앞으로 갈 수 있도록 정렬한다.
    return a.second > b.second;
}
int main(void) {
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        m1[temp] += 1; // MARK: 빈도수를 알 수 있는 맵을 만든다. 또한 맵은 기본적으로 정렬이 되는 자료구조기 때문에
        if(!m2[temp]) m2[temp] = i + 1; // MARK: 나온 순서를 알 수 있도록 하는 맵을 따로 만든다.
    }
    for(auto it: m1) // MARK: 맵에 있는 데이터들을 따로 또 정렬을 할 수 있게끔 vector에 넣는다
        v.push_back(make_pair(it.first, it.second));
    sort(v.begin(), v.end(), comp);
    for(auto j: v)
        for(int i = 0; i < j.second; i++)
            cout << j.first << " ";
    return 0;
}

/*
 #include <bits/stdc++.h>
 using namespace std;
 vector<pair<int, int> > v;
 int n, c, temp, flag = 1;
 bool comp(const pair<int, int>& a, const pair<int, int>& b) {
     return a.second > b.second;
 }
 int main(void) {
     cin >> n >> c;
     for(int i = 0; i < n; i++) {
         cin >> temp;
         if(v.size()) {
             flag = 1;
             for(int i = 0; i < v.size(); i++) {
                 if(v[i].first - temp == 0) {
                     v[i].second += 1;
                     flag = 0;
                 }
             }
         }
         if (flag) v.push_back(make_pair(temp, 1));
     }
     sort(v.begin(), v.end(), comp); // MARK:  stable_sort로 바꾸면 되는 문제라고 한다. sort와 stable_sort에 대해서 제대로 공부를 해봐야겠다.
     for(auto j: v)
         for(int i = 0; i < j.second; i++)
             cout << j.first << " ";
     return 0;
 }
 // MARK: 왜 틀렸는지 모르겠다.
 */
