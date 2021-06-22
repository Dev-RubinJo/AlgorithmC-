/*
이 문제는 혼자서 해결을 하지 못하여 https://kimtaehyun98.tistory.com/67 이 블로그를 참고했다. 

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[31][31];

void func() {
    for(int i = 0; i <= 30; i++) {
        for(int j = 0; j <= 30; j++) {
            if(i > j) continue;
            if(i == 0) dp[j][i] = 1;
            else dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
        }
    }
}

void input() {
    func();

    while(1) {
        cin >> n;
        if(!n) return;
        cout << dp[n][n] << '\n';
    }
}

int main(void) {
    input();
    return 0;
}