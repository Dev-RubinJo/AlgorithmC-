//
//  2852-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/03.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, t, w, mm, ss, rmm, rss;
map<int, int> m1;
vector<pair<int, string> > v;
string m;
string s1, s2;
string r1 = "00:00", r2 = "00:00";
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t >> m;
        v.push_back(make_pair(t, m));
    }
    for(int i = 0; i < v.size(); i++) {
        m1[v[i].first] += 1;
        if(m1[1] == m1[2]) {
            if(w == 1) {
                rmm = stoi(r1.substr(0, 2));
                rss = stoi(r1.substr(3, 2));
                mm = stoi(v[i].second.substr(0, 2)) - stoi(s1.substr(0, 2)) + rmm;
                ss = stoi(v[i].second.substr(3, 2)) - stoi(s1.substr(3, 2)) + rss;
                if(ss > 59) {
                    mm += 1;
                    ss -= 60;
                } else if (ss < 0) {
                    mm -= 1;
                    ss += 60;
                }
                m = to_string(mm);
                if(m.size() == 1) {
                    m.insert(0, "0");
                }
                r1 = m;
                m = to_string(ss);
                if(m.size() == 1) {
                    m.insert(0, "0");
                }
                r1 += ":" + m;
            } else if(w == 2) {
                rmm = stoi(r2.substr(0, 2));
                rss = stoi(r2.substr(3, 2));
                mm = stoi(v[i].second.substr(0, 2)) - stoi(s2.substr(0, 2)) + rmm;
                ss = stoi(v[i].second.substr(3, 2)) - stoi(s2.substr(3, 2)) + rss;
                if(ss > 59) {
                    mm += 1;
                    ss -= 60;
                } else if (ss < 0) {
                    mm -= 1;
                    ss += 60;
                }
                m = to_string(mm);
                if(m.size() == 1) {
                    m.insert(0, "0");
                }
                r2 = m;
                m = to_string(ss);
                if(m.size() == 1) {
                    m.insert(0, "0");
                }
                r2 += ":" + m;
            }
            w = 3;
            s1 = v[i].second;
            s2 = v[i].second;
            if(i == v.size() - 1) {
                w = 3;
            }
        } else if (m1[1] > m1[2] && w != 1) {
            w = 1;
            s1 = v[i].second;
        } else if (m1[1] < m1[2] && w != 2) {
            w = 2;
            s2 = v[i].second;
        }
    }
    if(w == 1) {
        rmm = stoi(r1.substr(0, 2));
        rss = stoi(r1.substr(3, 2));
        mm = 48 - stoi(s1.substr(0, 2)) + rmm;
        ss = 0 - stoi(s1.substr(3, 2)) + rss;
        if(ss > 59) {
            mm += 1;
            ss -= 60;
        } else if (ss < 0) {
            mm -= 1;
            ss += 60;
        }
        m = to_string(mm);
        if(m.size() == 1) {
            m.insert(0, "0");
        }
        r1 = m;
        m = to_string(ss);
        if(m.size() == 1) {
            m.insert(0, "0");
        }
        r1 += ":" + m;
    } else if (w == 2) {
        rmm = stoi(r2.substr(0, 2));
        rss = stoi(r2.substr(3, 2));
        mm = 48 - stoi(s2.substr(0, 2)) + rmm;
        ss = 0 - stoi(s2.substr(3, 2)) + rss;
        if(ss > 59) {
            mm += 1;
            ss -= 60;
        } else if (ss < 0) {
            mm -= 1;
            ss += 60;
        }
        m = to_string(mm);
        if(m.size() == 1) {
            m.insert(0, "0");
        }
        r2 = m;
        m = to_string(ss);
        if(m.size() == 1) {
            m.insert(0, "0");
        }
        r2 += ":" + m;
    }
    cout << r1 << '\n' << r2;
    return 0;
}

/*
 #include <bits/stdc++.h>
 using namespace std;
 vector<pair<int, pair<int, int> > > v;
 int n;
 map<int, int> t;
 pair<int, int> t1t, t2t, temp1, temp2;
 int main(void){
     cin >> n;
     for(int i = 0; i < n; i++) {
         int a; string s;
         cin >> a >> s;
         v.push_back(make_pair(a, make_pair(stoi(s.substr(0, 2)), stoi(s.substr(3, 2)))));
     }
     for(int i = 0; i < v.size(); i++) {
         t[v[i].first] += 1;
         if(t[1] == t[2]) {
             if(t[1]) {
                 int m = (v[i].second.first - temp1.first);
                 int s =(v[i].second.second - temp1.second);
                 if(s > 59) { m += 1; s -= 60; }
                 else if (s < 0) { m -= 1; s += 60; }
                 t1t = make_pair((v[i].second.first - temp1.first), (v[i].second.second - temp1.second));
             } else if (t[2]) {
                 int m = (v[i].second.first - temp2.first);
                 int s =(v[i].second.second - temp2.second);
                 if(s > 59) { m += 1; s -= 60; }
                 else if (s < 0) { m -= 1; s += 60; }
                 t2t = make_pair((v[i].second.first - temp1.first), (v[i].second.second - temp1.second));
             }
         } else if (t[1] > t[2]) {
             temp1 = v[i].second;
         } else {
             temp2 = v[i].second;
         }
     }
     
     return 0;
 }

 */
