//
//  두개 뽑아서 더하기-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/12.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

vector<int> solution(vector<int> numbers) {
    set<int> s;
    vector<int> orders;
    for(int i = 0; i < numbers.size() - 2; i++) orders.push_back(0);
    for(int i = 0; i < 2; i++) orders.push_back(1);
    do {
        int temp = 0;
        for(int i = 0; i < numbers.size(); i++) if(orders[i]) temp += numbers[i];
        s.insert(temp);
    } while(next_permutation(orders.begin(), orders.end()));
    vector<int> answer;
    for(int a: s) answer.push_back(a);
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> sol1 = solution({2,1,3,4,1});
    for(int i: sol1) {
        cout << i << endl;
    }
    cout << endl;
    
    sol1 = solution({5,0,2,7});
    for(int i: sol1) {
        cout << i << endl;
    }
    return 0;
}
