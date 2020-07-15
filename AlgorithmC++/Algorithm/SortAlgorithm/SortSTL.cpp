//
//  SortSTL.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/07/11.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    int score;
    Student(string name, int score) {
        this->name = name;
        this->score = score;
    }
    
    bool operator < (const Student &student) const {
        return this->score > student.score;
    }
};

bool compare(int a, int b) {
    return a < b;
}

bool comparePair(pair<string, pair<int, int> > a, pair<string, pair<int, int> > b) {
    if(a.second.first == b.second.first) {
        return a.second.second < b.second.second;
    } else {
        return a.second.first < b.second.first;
    }
}

int main() {
    
    int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
    sort(a, a + 10);
    
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    sort(a, a + 10, compare);
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    Student student[] = {
        Student("me", 32),
        Student("1", 33),
        Student("2", 34),
        Student("3", 35),
        Student("4", 36),
    };
    
    sort(student, student + 5);
    
    for(int i = 0; i < 5; i++) {
        cout << student[i].name << endl;
    }
    
    vector<pair<int, string> > v;
    v.push_back(pair<int, string>(90, "4"));
    v.push_back(pair<int, string>(85, "3"));
    v.push_back(pair<int, string>(82, "2"));
    v.push_back(pair<int, string>(98, "5"));
    v.push_back(pair<int, string>(79, "1"));
    
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].second << " ";
    }
    cout << endl;
    
    vector<pair<string, pair<int, int> > > vp;
    vp.push_back(pair<string, pair<int, int> >("1", pair<int, int>(90, 20190102)));
    vp.push_back(pair<string, pair<int, int> >("3", pair<int, int>(91, 20190101)));
    vp.push_back(pair<string, pair<int, int> >("2", pair<int, int>(94, 20190101)));
    vp.push_back(pair<string, pair<int, int> >("5", pair<int, int>(92, 20190101)));
    vp.push_back(pair<string, pair<int, int> >("4", pair<int, int>(90, 20190103)));
    
    sort(vp.begin(), vp.end(), comparePair);
    for(int i = 0; i < vp.size(); i++) {
        cout << vp[i].first << " ";
    }
    
    return 0;
}
