#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int INF = 100000000;
vector<pair<int, int>> a[7]; // 간선정보
int d[7]; // 최소 비용

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq; // 힙 대용으로 사용
    pq.push(make_pair(0, start));
    // 가까운 순서대로 처리하기 위해 큐를 사용
    while(!pq.empty()) {
        int current = pq.top().second;
        // 짧은 것이 먼저 오도록 (-)음수화를 한다.
        int distance = -pq.top().first;
        pq.pop();
        // 최단 거리가 아닌경우 스킵
        if(d[current] < distance) continue;
        for(int i = 0; i < a[current].size(); i++) {
            // 선택된 노드의 인접노드
            int next = a[current][i].first;
            // 선택된 노드를 거쳐서 인접노드로 가는 비용
            int nextDistance = distance + a[current][i].second;
            //기존의 최소 비용보다 더 저렴하다면 교체
            if(nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main(void) {
    for(int i = 1; i <= number; i++) {
        d[i] = INF;
    }
    a[1].push_back(make_pair(2, 2));
    a[1].push_back(make_pair(3, 5));
    a[1].push_back(make_pair(4, 1));

    a[2].push_back(make_pair(1, 2));
    a[2].push_back(make_pair(3, 3));
    a[2].push_back(make_pair(4, 2));

    a[3].push_back(make_pair(1, 5));
    a[3].push_back(make_pair(2, 3));
    a[3].push_back(make_pair(4, 3));
    a[3].push_back(make_pair(5, 1));
    a[3].push_back(make_pair(6, 5));

    a[4].push_back(make_pair(1, 1));
    a[4].push_back(make_pair(2, 2));
    a[4].push_back(make_pair(3, 3));
    a[4].push_back(make_pair(5, 1));

    a[5].push_back(make_pair(3, 1));
    a[5].push_back(make_pair(4, 1));
    a[5].push_back(make_pair(6, 2));

    a[6].push_back(make_pair(3, 5));
    a[6].push_back(make_pair(5, 2));
    
    dijkstra(1);

    for(int i = 1; i <= number; i++) {
        cout << d[i] << " ";
    }

    return 0;
}