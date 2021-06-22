//
//  19942-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/09.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
int n, mp, mf, ms, mv, a[16][5], mc = 999999999;
int p, f, s, v, c;
map<int, vector<vector<int>>> res;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];

    for(int i = 1; i < (1 << n); i++) {
        p = f = s = v = c = 0;
        vector<int> ve;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                ve.push_back(j + 1);
                p += a[j][0]; f += a[j][1]; s += a[j][2]; v += a[j][3]; c += a[j][4];
            }
        }
        if(p >= mp && f >= mf && s >= ms && v >= mv) { // MARK: 처음에 mf를 mp로 해서 엄청 여러번 틀린 문제. 멍청이였다...
            if(mc >= c) {
                mc = c;
                res[mc].push_back(ve);
            }
        }
    }
    if(mc == 999999999) cout << -1 << endl;
    else {
        sort(res[mc].begin(), res[mc].end());
        cout << mc << endl;
        for(auto a: res[mc][0]) cout << a << " ";
    }
    return 0;
}
// MARK: 이 문제는 정말 어떻게 풀어야할지 감이 안와서 결국 큰돌님 답을 보고 풀었다. 체화될때까지 여러번 풀어야되는 문제
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//#define endl "\n";
//int n, mp, mf, ms, mv, mc = 9999999, a[16][6];
//int p = 0, f = 0, s = 0, v = 0, c = 0;
//int order[15], ans[15], cnt, ansTemp[15];
//int main(void) {
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cin >> n;
//    cin >> mp >> mf >> ms >> mv;
//    for(int i = 0; i < n; i++) {
//        a[i][0] = i + 1;
//        cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
//    }
//    for(int i = 0; i < n; i++) order[i] = i;
//    do {
//        p = 0; f = 0; s = 0; v = 0; c = 0;
//        for(int i = 0; i < 4; i++) {
//            p += a[order[i]][1]; f += a[order[i]][2]; s += a[order[i]][3]; v += a[order[i]][4]; c += a[order[i]][5];
//            ansTemp[i] = a[order[i]][0];
//            if(p >= mp && f >= mf && s >= ms && v >= mv && mc > c) {
//                mc = min(mc, c);
//                for(int j = 0; j < i + 1; j++) ans[j] = ansTemp[j];
//                cnt = i + 1;
//                break;
//            }
//        }
//    } while(next_permutation(order, order + n));
//
//    if(mc == 9999999) cout << -1;
//    else {
//        cout << mc << endl;
//        for(int i = 0; i < cnt; i++) {
//            cout << ans[i] << " ";
//        }
//    }
//
//    return 0;
//}
