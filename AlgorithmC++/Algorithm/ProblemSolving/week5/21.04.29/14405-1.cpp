#include <bits/stdc++.h>
using namespace std;
string s;
int flag;
int main(void) {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != 'p' && s[i] != 'k' && s[i] != 'c') { flag = 1; break; }
        if(s[i] == 'p') {
            i += 1;
            if(s[i] != 'i') {
                flag = 1;
                break;
            }
        }
        if(s[i] == 'k') {
            i += 1;
            if(s[i] != 'a') {
                flag = 1;
                break;
            }
        }
        if(s[i] == 'c') {
            i += 1;
            if(s[i] != 'h') {
                flag = 1;
                break;
            }
            i += 1;
            if(s[i] != 'u') {
                flag = 1;
                break;
            }
        }
    }
    if(flag) cout << "NO";
    else cout << "YES";
    return 0;
}