#include <bits/stdc++.h>
using namespace std;
int n;
double arr[10001], ans, tmp;

int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    tmp = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > tmp * arr[i]) tmp = arr[i];
        else tmp *= arr[i];
        ans = max(ans, tmp);
    }

    printf("%.3lf", ans + 0.00001);
    return 0;
}