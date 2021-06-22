//
//  1285-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/09.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
pair<int, int> nums[21][21];
int n, flag, x, y;
char c[21][21];
void checkT(int y, int x) {
    int a = 0, b = 0;
    for(int i = 0; i < n; i++)
        if(c[y][i] == 'T') a += 1;
    for(int i = 0; i < n; i++)
        if(c[i][x] == 'T') b += 1;
    nums[y][x] = make_pair(a, b);
}
pair<int, int> findMax() {
    pair<int, int> a = {0, 0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!nums[i][j].first && !nums[i][j].second) flag = 1;
            else {
                flag = 0;
                if(nums[i][j].first >= a.first && nums[i][j].second >= a.second) {
                    a.first = nums[i][j].first; a.second = nums[i][j].second;
                    x = j; y = i;
                }
            }
        }
    }
    return a;
}
int main(void) {
//    cin >> n;
//    for(int i = 0; i < n; i++)
//        for(int j = 0; j < n; j++) cin >> c[i][j];
//    while(1) {
//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < n; j++) checkT(i, j);
//        pair<int, int> maxT = findMax();
//        if(!flag) {
//            if(maxT.first >= maxT.second) {
//                for(int i = 0; i < n; i++)
//                    c[y][i] = (c[y][i] == 'T') ? 'H' : 'T';
//            } else {
//                for(int i = 0; i < n; i++)
//                    c[i][x] = (c[i][x] == 'T') ? 'H' : 'T';
//            }
//        } else {
//            break;
//        }
//    }
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) {
//            cout << nums[i][j].first << ":" << nums[i][j].second << " ";
//        }
//        cout << endl;
//    }
    
    int c[6] = {1, 0, 0, 0, 0, 1};
    do {
        for (int a: c) cout << a << " ";
        cout << endl;
    } while(next_permutation(c, c + 6));
    return 0;
}
