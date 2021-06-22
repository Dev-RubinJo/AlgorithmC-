//
//  16562-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/02/17.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <iostream>
using namespace std;

int getParent(int parent[], int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a == b) return 1;
    return 0;
}

int main(){
    int f[10001], price[10001], n, m, k;
    int check[10001];
    int a, b;
    int res = 0;

    cin >> n >> m >> k;
    for(int i = 1; i < n + 1; i++){
        cin >> price[i];
        f[i] = i;
    }
    
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        unionParent(f, a, b);
    }

    for(int i = 1; i < n + 1; i++) {
        int node = getParent(f, i);
        if (check[node]) continue;
        check[node] = true;
        res += price[node];
    }

    if(res <= k) cout << res;
    else cout << "Oh no";
}
