#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    map<string, int> m;
    vector<int> answer;
    int s = 0, e = 0, len = INT_MAX, te, ts, cnt;
    for(string g: gems) m[g] = 0;
    
    while(1) {
        if(cnt == m.size()) {
            if(e - s < len) {
                te = e;
                ts = s;
                len = e - s;
            }
            if(m[gems[s]] > 1){
                m[gems[s]] -= 1;
                s += 1;
            } else {
                m[gems[s]] -= 1;
                s += 1;
                cnt -= 1;
            }
        } else {
            if(e == gems.size()) break;
            if(!m[gems[e]]) cnt += 1;
            m[gems[e]] += 1;
            e += 1;
        }
    }
    answer.push_back(ts + 1);
    answer.push_back(te);
    return answer;
}

int main(void) {

    return 0;
}