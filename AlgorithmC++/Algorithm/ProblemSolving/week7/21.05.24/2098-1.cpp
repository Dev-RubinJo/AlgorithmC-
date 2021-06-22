/*
이 문제는 그냥 dfs로 풀게 되면 시간복잡도가 O(n!)가 나온다. 처음 시작점부터 나머지로 갈 수록 적어지는 n x (n - 1) x ... x 2 x 1 이 형태
즉 그냥 풀면 미친 시간이 나온다는 것이다.
그래서 이 문제는 갈 수 있는 경로마다의 최저값을 저장해두고 다른 경로에서 이 경로로 갔을 경우 저장된 값이 있다면 그 값을 반환해주는 방식으로
시간을 줄여나가야 한다. 즉 dp로 풀어야 하는 문제. 

다만 이제 이 문제에서 모든 입력은 순회할 수 있는 경우만을 제공한다고 했으니 순회는 당연한 것이고 어떻게 방문을 할 수 있을지 그 부분을 봐야하는데
이를 비트마스킹으로 해결했다. C++, C에서 비스마스킹을 적용할 수 있는 범위가 보통 n이 30정도 까지니 최대 도시 개수가 16개인 이 문제에서는
충분히 비트마스킹으로 풀 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;
int n, m1[16][16], dp[16][1 << 16];
int maxv = 987654321;
void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m1[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
}

int tsp(int idx, int v) {
    if(v == (1 << n) - 1) {
        return m1[idx][0] ? m1[idx][0] : maxv;
    }
    int &res = dp[idx][v];
    if(res != -1) return res;
    res = maxv;
    for(int i = 0; i < n; i++) {
        if(v & (1 << i)) continue;
        if(m1[idx][i] == 0) continue;
        res = min(res, tsp(i, v | (1 << i)) + m1[idx][i]);
    }
    return res;
}

int main(void) {
    input();
    cout << tsp(0, 1);
    return 0;
}