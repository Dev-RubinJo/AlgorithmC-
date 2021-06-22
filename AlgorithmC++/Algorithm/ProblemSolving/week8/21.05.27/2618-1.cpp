/*
https://yabmoons.tistory.com/644 이 링크를 참고하여 문제 품
*/

#include <bits/stdc++.h>
using namespace std;
int n, w, dp[1001][1001];
vector<pair<int, int>> v(1001);

void input() {
    cin >> n;
    cin >> w;
    for(int i = 1; i <= w; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }
    memset(dp, -1, sizeof(dp));
}

int getTerm(int fy, int fx, int sy, int sx) {
    return abs(fy - sy) + abs(fx - sx);
}

int func1(int p1, int p2) {
    if(p1 == w || p2 == w) return 0;
    if(dp[p1][p2] != -1) return dp[p1][p2];
    int next = max(p1, p2) + 1;
    int dist1, dist2;
    if(p1 == 0) dist1 = getTerm(1, 1, v[next].first, v[next].second);
    else dist1 = getTerm(v[p1].first, v[p1].second, v[next].first, v[next].second);

    if(p2 == 0) dist2 = getTerm(n, n, v[next].first, v[next].second);
    else dist2 = getTerm(v[p2].first, v[p2].second, v[next].first, v[next].second);

    int res1 = dist1 + func1(next, p2);
    int res2 = dist2 + func1(p1, next);

    return dp[p1][p2] = min(res1, res2);
}

void route(int p1, int p2) {
    if(p1 == w || p2 == w) return;
    int next = max(p1, p2) + 1;
    int dist1, dist2;

    if(p1 == 0) dist1 = getTerm(1, 1, v[next].first, v[next].second);
    else dist1 = getTerm(v[p1].first, v[p1].second, v[next].first, v[next].second);

    if(p2 == 0) dist2 = getTerm(n, n, v[next].first, v[next].second);
    else dist2 = getTerm(v[p2].first, v[p2].second, v[next].first, v[next].second);

    if(dp[next][p2] + dist1 < dp[p1][next] + dist2) {
        cout << 1 << '\n';
        route(next, p2);
    } else {
        cout << 2 << '\n';
        route(p1, next);
    }
    return;
}

int main(void) {
    input();
    cout << func1(0, 0) << '\n';
    route(0, 0);
    return 0;
}

// #include <iostream>
// #include <cstring>
 
// #define endl "\n"
// #define MAX 1010
// using namespace std;
 
// struct COORD
// {
//     int x;
//     int y;
// };
 
// int N, W;
// int DP[MAX][MAX];
// COORD Event[MAX];
 
// int Max(int A, int B) { return A > B ? A : B; }
// int Min(int A, int B) { return A < B ? A : B; }
 
// void Input()
// {
//     cin >> N >> W;
//     for (int i = 1; i <= W; i++)
//     {
//         cin >> Event[i].x >> Event[i].y;
//     }
// }
 
// int Find_Dist(int x, int y, int xx, int yy) { return abs(xx - x) + abs(yy - y); }
 
// int Total_Distance(int Police1, int Police2)
// {
//     if (Police1 == W || Police2 == W) return 0;
//     if (DP[Police1][Police2] != -1) return DP[Police1][Police2];
    
//     int Next_Event = Max(Police1, Police2) + 1;
//     int Dist1, Dist2;
 
//     if (Police1 == 0) Dist1 = Find_Dist(1, 1, Event[Next_Event].x, Event[Next_Event].y);
//     else Dist1 = Find_Dist(Event[Police1].x, Event[Police1].y, Event[Next_Event].x, Event[Next_Event].y);
 
//     if (Police2 == 0) Dist2 = Find_Dist(N, N, Event[Next_Event].x, Event[Next_Event].y);
//     else Dist2 = Find_Dist(Event[Police2].x, Event[Police2].y, Event[Next_Event].x, Event[Next_Event].y);
 
//     int Result1 = Dist1 + Total_Distance(Next_Event, Police2);
//     int Result2 = Dist2 + Total_Distance(Police1, Next_Event);
//     DP[Police1][Police2] = Min(Result1, Result2);
//     return DP[Police1][Police2];
// }
 
// void Route(int P1, int P2)
// {
//     if (P1 == W || P2 == W) return;
    
//     int Next_Event = Max(P1, P2) + 1;
//     int Dist1, Dist2;
 
//     if (P1 == 0) Dist1 = Find_Dist(1, 1, Event[Next_Event].x, Event[Next_Event].y);
//     else Dist1 = Find_Dist(Event[P1].x, Event[P1].y, Event[Next_Event].x, Event[Next_Event].y);
 
//     if (P2 == 0) Dist2 = Find_Dist(N, N, Event[Next_Event].x, Event[Next_Event].y);
//     else Dist2 = Find_Dist(Event[P2].x, Event[P2].y, Event[Next_Event].x, Event[Next_Event].y);
 
//     if (DP[Next_Event][P2] + Dist1 < DP[P1][Next_Event] + Dist2)
//     {
//         cout << 1 << endl;
//         Route(Next_Event, P2);
//     }
//     else
//     {
//         cout << 2 << endl;
//         Route(P1, Next_Event);
//     }
// }
 
// void Solution()
// {
//     memset(DP, -1, sizeof(DP));
//     cout << Total_Distance(0, 0) << endl;
//     Route(0, 0);
// }
 
// void Solve()
// {
//     Input();
//     Solution();
// }
 
// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
 
//     //freopen("Input.txt", "r", stdin);
//     Solve();
 
//     return 0;
// }

