#include<bits/stdc++.h>
using namespace std;   
int n, k, id, cost_time, _time, idx;
long long ans; 
struct Cacher{
    int id, maxTime, cacher_id;  
}; 
struct comp{
    bool operator()(Cacher & a, Cacher & b){
        if(a.maxTime == b.maxTime){
            return a.cacher_id > b.cacher_id; 
        }
        return a.maxTime > b.maxTime;  
    }
}; 

bool cmp2(const Cacher & a, const Cacher & b){
    if(a.maxTime == b.maxTime){
        return a.cacher_id > b.cacher_id; 
    }
    return a.maxTime < b.maxTime; 
}
priority_queue<Cacher, vector<Cacher>, comp> pq; 
vector<Cacher> v; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  
    cin >> n >> k;  
    for(int i = 0; i < n; i++){
        cin >> id >> cost_time; 
        if(i < k){
            pq.push({id, cost_time, i + 1});   
            continue;
        }    
        pq.push({id, cost_time + pq.top().maxTime, pq.top().cacher_id});  
        v.push_back(pq.top());
        pq.pop();    
    }   
    while(pq.size()){  
        v.push_back(pq.top());
        pq.pop();
    } 
    sort(v.begin(), v.end(), cmp2);
    for(int i = 0; i < v.size(); i++){
        ans += (i + 1) * (long long)v[i].id; 
    }
    cout << ans << "\n"; 
    return 0;
}   




/*
#include <bits/stdc++.h>
using namespace std; 
long long ans;
int n, k, id, w;
deque<int> order;
priority_queue<pair<int, deque<pair<int, int>>>> pq;
vector<deque<pair<int, int>>> vv;
bool flag, emp[100000];


void makeRow(int idd, int ww) {
    if(pq.size() < k) {
        deque<pair<int, int>> v;
        v.push_back({idd, ww});
        pq.push(make_pair(-ww, v));
    } else {
        auto first = pq.top(); pq.pop();
        first.first -= ww;
        first.second.push_back({idd, ww});
        pq.push(first);
    }
}

void input() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> id >> w;
        makeRow(id, w);
    }
}

void func() {
    while(!pq.empty()) {
        vv.push_back(pq.top().second);
        pq.pop();
    }
    while(!flag) {
        for(int i = 0; i < vv.size(); i++) {
            if(vv[i].empty()) {
                emp[i] = 1;
            } else {
                vv[i].front().second -= 1;
                if(vv[i].front().second <= 0) {
                    order.push_back(vv[i].front().first);
                    vv[i].pop_front();
                }
            }
        }
        for(int i = 0; i < vv.size(); i++) {
            if(emp[i]) {
                flag = 1;
            } else {
                flag = 0;
            }
        }
    }
    for(int i = 1; i <= order.size(); i++) {
        ans += order[i] * i;
    }

    cout << ans;
}

int main(){
	input();
    func();
	return 0; 
}
*/