//
//  9934-1.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2021/04/13.
//  Copyright © 2021 YooBin Jo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int n, d, a[1025];
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < (1 << n) - 1; i++)
        cin >> a[i];
    int term = 0;
    for(int i = 0; i < n; i++) {
        if(i) term = (1 << n) / (1 << i);
        for(int j = 0; j < (1 << i); j++) {
            if (!i) cout << a[(1 << n) / 2 - 1] << " ";
            else if(i != n - 1) cout << a[((1 << n) / (2 << i) - 1) + (term * j)] << " ";
            else cout << a[(term * j)] << " ";
        }
        cout << endl;
    }
    return 0;
}
// MARK: 완전 이진트리를 구현하지 않고 그 특징만을 이용해서 푼 문제. 완전 이진트리를 만들어서 푸는 방법도 구현해봐야한다.
//cin >> d;
//if((1 << n) % i) {
//    if(i % 4 == 0) {
//
//    }
//}
/*
 #include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define endl '\n'
 struct Node {
     int data;
     struct Node *l, *r;
     Node(int data) {
         this->data = data;
         l = r = NULL;
     }
 };
 int n, d, a[1025];
 int main(void) {
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cin >> n;
 //    struct Node * root = new Node(-1);
     for(int i = 0; i < (1 << n); i++) {
         cin >> a[i];
     }
     int term = 0;
     for(int i = 0; i < n; i++) {
         if(i) term = (1 << n) / (2 * i);
         for(int j = 0; j < (1 << i); j++) {
             if (!i) {
                 cout << a[(1 << n) / 2 - 1] << " ";
             } else if(i != n - 1) {
                 if(!j) cout << a[(1 << n) / (2 * (i + 1)) - 1] << " ";
                 else cout << a[((1 << n) / (2 * (i + 1)) - 1) + (term * j)] << " ";
             } else {
                 if(!j) cout << a[0] << " ";
                 else cout << a[(term * j)] << " ";
             }
         }
         cout << endl;
     }
     return 0;
 }
 */
