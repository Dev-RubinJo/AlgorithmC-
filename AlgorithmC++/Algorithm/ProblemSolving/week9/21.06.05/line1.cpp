#include <bits/stdc++.h>
using namespace std;

int solution(string inputString) {
    int answer = 0;
    int last = inputString[inputString.size() - 1] - '0';
    int up = 0;
    char pre = inputString[0];
    for(int i = 0; i < inputString.size(); i++) {
        if((i < (inputString.size() - 1) && (inputString[i] - '0') == last) || (i > 0 && pre >= inputString[i])) {
            up += 1;
            pre = inputString[i];
        }
    }
    return up * 10 + last;
}