//
//  BaekJoon1599.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/23.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a < b;
}

int main(void) {
    
    int n;
    vector<string> str;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < temp.size(); j++) {
            if(temp[j] == 'k') temp[j] = 'c';
            else if(temp[j] == 'n' && temp[j + 1] == 'g') {
                temp[j] = 'o';
                temp.erase(temp.begin() + j + 1);
            } else if(temp[j] == 'o') temp[j] = 'p';
            else if(temp[j] == 'p') temp[j] = 'q';
        }
        str.push_back(temp);
    }
    
    
    
    sort(str.begin(), str.end());
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < str[i].size(); j++) {
            if(str[i][j] == 'c') str[i][j] = 'k';
            else if(str[i][j] == 'o') {
                str[i][j] = 'n';
                str[i].insert(str[i].begin() + j + 1, 'g');
            }
            else if(str[i][j] == 'p') str[i][j] = 'o';
            else if(str[i][j] == 'q') str[i][j] = 'p';
        }
        cout << str[i] << "\n";
    }

    
    return 0;
}
