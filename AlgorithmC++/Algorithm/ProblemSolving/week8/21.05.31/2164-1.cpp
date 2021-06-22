#include <bits/stdc++.h>
using namespace std;
int n;
deque<int> arr;

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        arr.push_back(i);
    }
}

void rotate(int d) {
    // Push first d elements
    // from last to the beginning
    for (int i = 0; i < d; i++) {
        int val = arr.front();
        arr.pop_front();
        arr.push_back(val);
    }
}

void func() {
    while(arr.size() != 1) {
        arr.pop_front();
        rotate(1);
    }
    cout << arr[0];
}

int main() {
    input();
    func();
    return 0;
}