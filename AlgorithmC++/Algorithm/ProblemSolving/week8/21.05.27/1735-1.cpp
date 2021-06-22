// #include <bits/stdc++.h>
// using namespace std;
// int V, E, K, u, v, w;
// vector<pair<int, int>> adj[20001];
// int dist[20001];
// bool visited[20001];
// const int INF = 987654321;
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
// int main(){
// 	scanf("%d %d %d", &V, &E, &K);
// 	fill(dist, dist + 20001, INF);
// 	for(int i = 0; i < E; i++){
// 		scanf("%d %d %d", &u, &v, &w);
// 		adj[u].push_back(make_pair(w, v)); 
// 	}
// 	pq.push(make_pair(0, K));
// 	dist[K] = 0; 
// 	while(pq.size()){ 
// 		int here = pq.top().second;
// 		int here_dist = pq.top().first;
// 		pq.pop();
// 		if(dist[here] != here_dist) continue;
// 		for(pair<int, int> there : adj[here]){
// 			int _dist = there.first;  
// 			int _there = there.second; 
// 			if(dist[_there] > dist[here] + _dist){
// 				dist[_there] = dist[here] + _dist; 
// 				pq.push(make_pair(dist[_there], _there));  
// 			}  
// 		}
// 	} 
// 	for(int i = 1; i <= V; i++){ 
// 		if(dist[i] == INF) puts("INF");
// 		else printf("%d\n", dist[i]); 
// 	}
// 	return 0; 
// }


#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
typedef pair<int, int> pii;
int v, e, start;
vector<pii> a[20001];
int d[20001];
priority_queue<pii> pq;

void dijkstra(int start) {
    d[start] = 0;
    pq.push(pii(0, start));
    while(!pq.empty()) {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        if(d[current] != distance) continue;
        for(int i = 0; i < a[current].size(); i++) {
            int next_pos = a[current][i].first;
            int next_dis = distance + a[current][i].second;
            if(next_dis < d[next_pos]) {
                d[next_pos] = next_dis;
                pq.push(pii(-next_dis, next_pos));
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> v >> e;
    cin >> start;
    for(int i = 0; i < e; i++) {
        int aa, b, c; cin >> aa >> b >> c;
        a[aa].push_back(pii(b, c));
    }
    for(int i = 1; i <= v; i++) {
        d[i] = INF;
    }
    dijkstra(start);
    for(int i = 1; i <= v; i++) {
        if(d[i] != INF) cout << d[i] << '\n';
        else cout << "INF\n";
    }
    return 0;
}