//
//  BaekJoon1296.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/31.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main(void) {
    string oName;
    int n;
    int l = 0, o = 0, v = 0, e = 0;
    vector<pair<string, int> > names;
    
    cin >> oName;
    for(int i = 0; i < oName.size(); i++) {
        if(oName[i] == 'L') l += 1;
        else if(oName[i] == 'O') o += 1;
        else if(oName[i] == 'V') v += 1;
        else if(oName[i] == 'E') e += 1;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        int lt = l, ot = o, vt = v, et = e, temp;
        string name;
        cin >> name;
        for(int j = 0; j < name.size(); j++) {
            if(name[j] == 'L') lt += 1;
            else if(name[j] == 'O') ot += 1;
            else if(name[j] == 'V') vt += 1;
            else if(name[j] == 'E') et += 1;
        }
        temp = ((lt + ot) * (lt + vt) * (lt + et) * (ot + vt) * (ot + et) * (vt + et)) % 100;
        names.push_back(make_pair(name, temp));
    }
    sort(names.begin(), names.end(), compare);
    
    cout << names[0].first;
    
    return 0;
}
