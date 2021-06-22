#include <bits/stdc++.h>
using namespace std;
int number = 6;

// MARK: 전체 그래프 초기화
int a[6][6] = {
    {0, 2, 5, 1, INT_MAX, INT_MAX},
    {2, 0, 3, 2, INT_MAX, INT_MAX},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INT_MAX},
    {INT_MAX, INT_MAX, 1, 1, 0, 2},
    {INT_MAX, INT_MAX, 5, INT_MAX, 2, 0}
};

bool v[6]; // MARK: 방문한 노드
int d[6]; // MARK: 최단 거리

// MARK: 가장 최소 거리를 가지는 정점을 반환하는 함수
int getSmallIndex() {
    int min_value = INT_MAX;
    int idx = 0;
    for(int i = 0; i < number; i++) {
        if(d[i] < min_value && !v[i]) {
            min_value = d[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int start) {
    for(int i = 0; i < number; i++) {
        d[i] = a[start][i];
    }
    v[start] = 1;
    for(int i = 0; i < number - 2; i++) {
        int current = getSmallIndex();
        v[current] = 1;
        for(int j = 0; j < number; j++) {
            if(!v[j]) {
                if(d[current] + a[current][j] < d[j]) {
                    d[j] = d[current] + a[current][j];
                }
            }
        }
    }
}

int main(void) {
    dijkstra(0);
    for(int i = 0; i < number; i++) {
        cout << d[i] << " ";
    }
    return 0;
}