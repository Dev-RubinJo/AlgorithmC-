//
//  BaekJoon1764.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/08.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void) {
    int n, m, total = 0;
    map<string, int> people;
    vector<string> names;
    string name;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> name;
        people[name] += 1;
    }
    
    for(int i = 0; i < m; i++) {
        cin >> name;
        people[name] += 1;
    }
    
    for(map<string, int>::iterator it = people.begin(); it != people.end(); it++) {
        if(it->second == 2){
            names.push_back(it->first);
            total += 1;
        }
    }
    
    cout << total << "\n";
    for(int i = 0; i < names.size(); i++)
        cout << names[i] << "\n";
    
    
    return 0;
}
