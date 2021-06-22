//
//  1620-2.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/29.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m;
map<string, int> _map1;
map<int, string> _map2;
string temp[100002], str;
int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str;
        _map1[str] = i + 1;
        _map2[i + 1] = str;
    }
    for(int i = 0; i < m; i++) {
        cin >> temp[i];
    }
    for(int i = 0; i < m; i++) {
        if(temp[i][0] >= 'A' && temp[i][0] <= 'Z')
            cout << _map1[temp[i]] << '\n';
        else
            cout << _map2[stoi(temp[i])] << '\n';
    }
    return 0;
}
// MARK: 위 코드로 하면 시간초과가 안나는 이유가 무엇일까
/*
#include <bits/stdc++.h>
using namespace std;
int n, m;
map<string, int> _map1;
map<int, string> _map2;
string temp;
int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        _map1[temp] = i + 1;
        _map2[i + 1] = temp;
    }
    for(int i = 0; i < m; i++) {
        cin >> temp;
        if(temp[0] >= 'A' && temp[0] <= 'Z')
            cout << _map1[temp] << '\n';
        else
            cout << _map2[stoi(temp)] << '\n';
    }
}
*/
