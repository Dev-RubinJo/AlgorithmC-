//
//  1436-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, cnt = 666;
int main(void) {
    cin >> n;
    while(1) {
        if(to_string(cnt).find("666") != string::npos) n -= 1;
        if(!n) break;
        cnt += 1;
    }
    cout << cnt;
    return 0;
}
// MARK: 숫자를 하나씩 더해가며 666이 있는지 없는지 확인하는 생각을 못했다. 이 방식대로 하면 확실하게 n번째로 작은 666이 들어있는 숫자를 확인할 수 있다. 
