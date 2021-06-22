//
//  8911-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/03/31.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int tc;
string s;
int main(void) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        cin >> s;
        int curx = 0, cury = 0, curd = 0, minx = 0, miny = 0, maxx = 0, maxy = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == 'L')
                curd = (curd + 3) % 4;
            else if (s[j] == 'R')
                curd = (curd + 1) % 4;
            else if (s[j] == 'F') {
                curx += dx[curd]; cury += dy[curd];
            } else {
                curx -= dx[curd]; cury -= dy[curd];
            }
            maxx = max(curx, maxx);
            maxy = max(cury, maxy);
            minx = min(curx, minx);
            miny = min(cury, miny);
        }
        cout << (maxx - minx) * (maxy - miny) << '\n';
    }
    return 0;
}
