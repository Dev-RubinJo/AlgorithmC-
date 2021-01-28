//
//  무지의 먹방라이브.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/11.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long times = k, timeCount = 0;
    vector<pair<int, int> > list;
//    vector<pair<int, int> > ;
    for(int i = 0; i < food_times.size(); i++) {
        list.push_back(make_pair(i + 1, food_times[i]));
        timeCount += food_times[i];
    }
    if(timeCount <= k)
        return -1;
    
    sort(list.begin(), list.end(), compare);
    
    times -= list[0].second * food_times.size();
    list.erase(list.begin());
    sort(list.begin(), list.end());
    if(times < 0) {
        
    } else if(times == 0) {
        return list[0].second;
    }
    
    
    
    return answer;
}


int main(void) {
    cout << solution({8, 5, 6, 4}, 15) << "\n";
    
    return 0;
}


/*
 int solution(vector<int> food_times, long long k) {
     int answer = 0;
     long long times = 0, previous = 0, length = food_times.size();
     
     priority_queue<pair<int, int> > pq;
     vector<pair<int, int> > list;
     
     for(int i = 0; i < food_times.size(); i++) {
         pq.push(make_pair(-food_times[i], i + 1));
         times += food_times[i];
     }
     if(times <= k)
         return -1;
     times = 0;
     while(times + ((-pq.top().first - previous) * length) <= k) {
         int now = -pq.top().first;
         pq.pop();
         times += (now - previous) * length;
         length -= 1;
         previous = now;
     }
     
     while(!pq.empty()) {
         int food_time = -pq.top().first;
         int order = pq.top().second;
         pq.pop();
         list.push_back(make_pair(food_time, order));
     }
     sort(list.begin(), list.end(), compare);
     return answer = list[(k - times) % length].second;
 }
 */
