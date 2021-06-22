#include <bits/stdc++.h>
using namespace std;
int n, dp[1001][1001], point[51][3];
bool v[51];

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> point[i][0] >> point[i][1] >> point[i][2];
    }
    memset(dp, -1, sizeof(dp));
}

int func(int str, int intt) {
    int &res = dp[str][intt];
    if(res != -1) return res;
    res = 0;
    int pnt = 0;
    vector<int> q;
    
    for(int i = 0; i < n; i++) {
        if(point[i][0] <= str || point[i][1] <= intt) {
            res += 1;
            if(!v[i]) {
                v[i] = 1;
                pnt += point[i][2];
                q.push_back(i);
            }
        }
    }

    for(int p = 0; p <= pnt; p++) {
        int nstr = min(1000, str + p);
        int nintt = min(1000, intt + pnt - p);
        res = max(res, func(nstr, nintt));
    }

    for(int qq: q) {
        v[qq] = 0;
    }

    return res;
}

int main(void) {
    input();
    cout << func(1, 1);
    return 0;
}