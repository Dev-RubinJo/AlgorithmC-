//
//  BaekJoon2870.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/24.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b) {
    if(a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

int main(void) {
    int n;
    vector<string> list;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        string temp, temp2 = "";
        cin >> temp;
        
        for(int j = 0; j < temp.size(); j++) {
            if(temp[j] - '0' >= 0 && temp[j] - '0' <= 9) {
                temp2 += temp[j];
                if(j == temp.size() - 1) {
                    list.push_back(temp2);
                }
            } else {
                if(temp2 != "") {
                    list.push_back(temp2);
                    temp2 = "";
                }
            }
        }
    }
    
    for(int i = 0; i < list.size(); i++) {
        for(int j = 0; j <  list[i].size(); j++) {
            if(list[i][j] == '0' && j != list[i].size() - 1) {
                list[i].erase(list[i].begin() + j);
                j--;
            } else {
                break;
            }
        }
    }
    
    sort(list.begin(), list.end(), compare);
    for(int i = 0; i < list.size(); i++) {
        cout << list[i] << "\n";
    }
    
    
    return 0;
}
