#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    map<int, int> m1;
    int same = 0;
    for(int i = 0; i < lottos.size(); i++) 
        m1[lottos[i]] += 1;
    for(int i = 0; i < win_nums.size(); i++)
        if(m1[win_nums[i]]) same += 1;
    if(same || m1[0]) {
        answer.push_back(7 - (same + m1[0]));
    } else {
        answer.push_back(6);
    }
    if(!same) {
        answer.push_back(6);
    } else {
        answer.push_back(7 - same);    
    }
    sort(answer.begin(), answer.end());
    return answer;
}