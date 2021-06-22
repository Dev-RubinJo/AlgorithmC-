#include <bits/stdc++.h>
using namespace std;
int tc, tmp;
string mindp[101], maxdp[101];
vector<string> s[10];

string mincal(string a, string b) {
    if(a.size() == b.size()) return (a < b ? a : b);
    else return (a.size() < b.size() ? a : b);
}

string maxcal(string a, string b) {
    if(a.size() == b.size()) return (a > b ? a : b);
    else return (a.size() > b.size() ? a : b);
}

void makeDP() {
    for(int i = 8; i <= 100; i++) {
        for(int j = 2; j < 8; j++) {
            for(string ss: s[j]) {
                if(ss != "0") {
                    mindp[i] = mincal(mindp[i], mincal(mindp[i - j] + ss, ss + mindp[i - j]));
                    maxdp[i] = maxcal(maxdp[i], maxcal(maxdp[i - j] + ss, ss + maxdp[i - j]));
                } else {
                    mindp[i] = mincal(mindp[i], mindp[i - j] + "0");
                }
            }
        }
    }
}

void setup() {
    s[2].push_back("1");
    s[3].push_back("7");
    s[4].push_back("4");
    s[5].push_back("2");
    s[5].push_back("3");
    s[5].push_back("5");
    s[6].push_back("6");
    s[6].push_back("8");
    s[6].push_back("0");
    s[7].push_back("8");

    for(int i = 0; i < 101; i++) {
        mindp[i] = "99999999999999999999999999999999999999999999999999";
        maxdp[i] = "0";
    }

    mindp[2] = maxdp[2] = "1";
    mindp[3] = maxdp[3] = "7";
    mindp[4] = "4"; maxdp[4] = "11";
    mindp[5] = "2"; maxdp[5] = "71";
    mindp[6] = "6"; maxdp[6] = "111";
    mindp[7] = "8"; maxdp[7] = "711";
}

int main(void) {
    setup();
    makeDP();
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        cin >> tmp;
        cout << mindp[tmp] << " " << maxdp[tmp] << '\n';
    }
    return 0;
}