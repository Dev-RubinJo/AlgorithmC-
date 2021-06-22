#include<bits/stdc++.h>
using namespace std; 
const int n = 18; 
bool isP[20]; 
double a, b, dp[20][20][20]; 
double go(int idx, int x, int y){ // 재귀를 이용해서 dp를 top - dowm 방식으로 채워나간다. -- 2
    if(idx == n) return isP[x] || isP[y] ? 1.0 : 0.0; // x 혹은 y가 소수면 적어도 한 팀이 소수로 득점할 확률이 소수기 때문에 1의 확률을 리턴, 아니면 0의 확률을 리턴
    double &ret = dp[idx][x][y]; 
    if(ret > -0.5) return ret; 
    ret = 0.0; // 해당 위치의 값을 0.0으로 다시 초기화
    ret += go(idx + 1, x + 1, y) * a * (1 - b); // a 만 득점할 확률
    ret += go(idx + 1, x + 1, y + 1) * a * b; // a, b 둘다 득점할 확률
    ret += go(idx + 1, x, y + 1) * (1 - a) * b; // b 만 득점할 확률
    ret += go(idx + 1, x, y) * (1 - a)* (1 - b); // a, b 둘다 득점하지 못할 확률
    return ret;  
} 
void era(){ // 에라토스테네스 체를 이용하여 먼저 소수 집합을 만들어 둔다. -- 1
    fill(isP, isP + 20, 1);
    isP[0] = 0; isP[1] = 0;  
    for(int i = 2; i <= 20; i++){ 
        for(int j = i + i; j <= 20; j += i){
            isP[j] = 0; 
        }
    }
}
int main(){ 
    scanf("%lf %lf", &a, &b); 
    a /= 100; b /= 100;  
    era();
    memset(dp, -1, sizeof(dp)); 
    printf("%.6lf", go(0, 0, 0));
}