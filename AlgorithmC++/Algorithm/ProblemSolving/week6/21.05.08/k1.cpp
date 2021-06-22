#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    while(true) {
        bool flag = 0;
        if(s.find("one") != string::npos) 
            s.replace(s.find("one"), 3, "1");
        if(s.find("two") != string::npos) 
            s.replace(s.find("two"), 3, "2");
        if(s.find("three") != string::npos) 
            s.replace(s.find("three"), 5, "3");
        if(s.find("four") != string::npos) 
            s.replace(s.find("four"), 4, "4");
        if(s.find("five") != string::npos) 
            s.replace(s.find("five"), 4, "5");
        if(s.find("six") != string::npos) 
            s.replace(s.find("six"), 3, "6");
        if(s.find("seven") != string::npos) 
            s.replace(s.find("seven"), 5, "7");
        if(s.find("eight") != string::npos) 
            s.replace(s.find("eight"), 5, "8");
        if(s.find("nine") != string::npos) 
            s.replace(s.find("nine"), 4, "9");
        if(s.find("zero") != string::npos) 
            s.replace(s.find("zero"), 4, "0");
        for(int i = 0; i < s.size(); i++) {
            if(s[i] - '0' < 0 || s[i] - '0' > 9) {
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        else break;
    }
    answer = stoi(s);
    return answer;
}

int main(void) {
    cout << solution("one4seveneight");
    return 0;
}