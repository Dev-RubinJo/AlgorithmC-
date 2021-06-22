#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    map<int, int> m1;
    for(int num: nums) m1[num] += 1;
    if(nums.size() / 2 < m1.size()) answer = nums.size() / 2;
    else answer = m1.size();
    
    return answer;
}

int main(void) {
    cout << solution({3,1,2,3});
    return 0;
}