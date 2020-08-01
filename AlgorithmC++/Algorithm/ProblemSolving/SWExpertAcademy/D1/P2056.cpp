//
//  P2056.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/02.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
    int test_case;
    int T;
    string date;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case) {
        int month = 0, day = 0;
        cin >> date;
        if (date.size() < 8) {
            cout << "#" << test_case << " " << -1 << "\n";
            continue;
        }
        for(int i = 0; i < 2; i++)
            month = (month * 10) + date[i + 4] - '0';
        for(int i = 0; i < 2; i++)
            day = (day * 10) + date[i + 6] - '0';
        
        if(month < 1 || month > 12) cout << "#" << test_case << " " << -1 << "\n";
        else {
            if (month == 1 && day > 0 && day < 32) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else if (month == 2 && day > 0 && day < 29) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else if (month == 3 && day > 0 && day < 32) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else if (month == 4 && day > 0 && day < 31) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else if (month == 5 && day > 0 && day < 32) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else if (month == 6 && day > 0 && day < 31) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else if (month == 7 && day > 0 && day < 32) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else if (month == 8 && day > 0 && day < 32) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else if (month == 9 && day > 0 && day < 31) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else if (month == 10 && day > 0 && day < 32) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else if (month == 11 && day > 0 && day < 31) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else if (month == 12 && day > 0 && day < 32) {
                cout << "#" << test_case << " " << date[0] << date[1] << date[2] << date[3] << "/" << date[4] << date[5] << "/" << date[6] << date[7] << "\n";
            } else {
                cout << "#" << test_case << " " << -1 << "\n";
            }
            
        }
        
    }
    
    
    return 0;
}
