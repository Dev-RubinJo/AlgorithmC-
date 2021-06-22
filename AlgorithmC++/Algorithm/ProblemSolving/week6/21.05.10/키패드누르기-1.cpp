#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int keys[4][4];
pii l, r;
void setMap() {
    keys[0][0] = 1; keys[0][1] = 2; keys[0][2] = 3;
    keys[1][0] = 4; keys[1][1] = 5; keys[1][2] = 6;
    keys[2][0] = 7; keys[2][1] = 8; keys[2][2] = 9;
    keys[3][0] = 10; keys[3][1] = 0; keys[3][2] = 11;
    l = pii(3, 0); r = pii(3, 2);
}

int calculateDistance(pii s, pii e) {
    return abs(s.first - e.first) + abs(s.second - e.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    setMap();
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            l = pii(numbers[i] / 3, 0);
        } else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            r = pii(numbers[i] / 3 - 1, 2);
        }
        else {
            pii current = pii(numbers[i] / 3, 1);
            if(!numbers[i]) current.first = 3;
            int left = calculateDistance(l, current);
            int right = calculateDistance(r, current);
            if(left > right) {
                answer += "R";
                r = current;
            } else if(left < right) {
                answer += "L";
                l = current;
            } else {
                if(hand == "right") {
                    answer += "R";
                    r = current;
                } else {
                    answer += "L";
                    l = current;
                }
            }
        }
    }
    return answer;
}