#include <bits/stdc++.h>
using namespace std;
int arr[9];

void input() {
    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
    }
}

void func() {
    sort(arr, arr + 9);
    do {
        int tmp = 0;
        for(int i = 0; i < 7; i++) {
            tmp += arr[i];
        }
        if(tmp == 100) {
            break;
        }
    } while(next_permutation(arr, arr + 9));
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << '\n';
    }
}

int main(void) {
    input();
    func();
    return 0;
}