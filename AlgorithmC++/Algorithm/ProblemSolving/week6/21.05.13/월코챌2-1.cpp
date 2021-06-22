#include <bits/stdc++.h>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int cnt[1004] = {0, };
    for(int i = 1; i <= right; i++) {
        for(int j = i; j <= right; j = j + i) {
            cnt[j] += 1;
        }
    }
    for(int i = left; i <= right; i++) {
        if(!(cnt[i] % 2)) answer += i;
        else answer -= i;
    }
    return answer;
}