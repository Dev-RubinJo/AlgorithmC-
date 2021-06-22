//
//  1068-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/04.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
vector<int> v[51];
int n, nd, del, cnt, start;
void dfs(int x) {
    if(v[x].empty()) {
        cnt += 1;
        return;
    }
    for(int i = 0; i < v[x].size(); i++) {
        dfs(v[x][i]);
    }
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nd;
        if(nd == -1) {
            start = i;
            continue;
        }
        v[nd].push_back(i);
    }
    cin >> del;
    if(del != start) {
        for(int i = 0; i < n; i++) {
            auto it = find(v[i].begin(), v[i].end(), del);
            if(it != v[i].end()) {
                v[i].erase(it);
            }
        }
        dfs(start);
        cout << cnt;
    } else
        cout << 0;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
vector<int> v[51];
int n, nd, del, cnt;
void dfs(int x) {
    if(v[x].empty()) {
        cnt += 1;
        return;
    }
    for(int i = 0; i < v[x].size(); i++) {
        dfs(v[x][i]);
    }
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nd;
        if(nd == -1) continue;
        v[nd].push_back(i);
    }
    cin >> del;
    if(del != 0) {
        for(int i = 0; i < n; i++) {
            auto it = find(v[i].begin(), v[i].end(), del);
            if(it != v[i].end()) {
                v[i].erase(it);
            }
        }
        dfs(0);
        cout << cnt;
    } else
        cout << 0;
    return 0;
} // MARK: 실패한 문제
 */
/*
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *left = NULL, *right = NULL;
    struct Node *root = NULL;
};
int n, node, lu, ru, cnt;
struct Node tree[51];
int postorder(struct Node *node) {
    if(node == NULL) {
        return 1;
    }
    lu = postorder(node->left);
    ru = postorder(node->right);
    if(lu == 1 && ru == 1)  {
        lu = 0; ru = 0;
        return cnt += 1;
    }
    else return cnt;
}
void deleteNode(struct Node *node, int d) {
    if(node == NULL) return;
    if(d % 2)
        node->left = NULL;
    else
        node->right = NULL;
}
void printPostorder(struct Node *node) {
    if(node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> node;
        if(node == -1) {
            tree[0].data = 0;
            continue;
        }
        tree[i].data = i;
        tree[i].root = &tree[node];
        if(i % 2) {
            tree[node].left = &tree[i];
        } else {
            tree[node].right = &tree[i];
        }
    }
    cin >> node;
    if(node) {
        deleteNode(tree[node].root, node);
        cout << postorder(&tree[0]);
    } else {
        cout << 0;
    }
    return 0;
}
*/
