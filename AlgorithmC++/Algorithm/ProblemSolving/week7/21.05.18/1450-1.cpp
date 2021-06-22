/*
이 문제를 완전탐색으로 풀 경우 시간복잡도: 2^n
이유는 n개의 물건이 있을 때 각 물건을 넣고 빼는 모든 경우의 수를 고려했을때다.
a, b, c, ... , n이 있을때 
a를 넣고 빼는 경우의 수 2개
b를 넣고 빼는 경우의 수 2개
c를 넣고 빼는 경우의 수 2개
.
.
.
n을 넣고 빼는 경우의 수 2개
이 모든 2를 다 곱했을때 완전탐색의 시간복잡도가 나오게 되는데 이때의 시간복잡도가 2^n이다.

또한 dp로 풀기에는 가능한 무게의 최대 범위가 1e9이기 때문에 공간 복잡도 상으로 좋지 못하다는 생각이 든다.

이 문제는 혼자서 못푼 문제다. https://velog.io/@asdsa2134/백준-10456-냅색문제 과 https://groti.tistory.com/17 이 블로그를 참고했다.

위에서 말했듯이 이 문제는 시간복잡도가 2^n이다. 하지만 물건의 최대 갯수가 30개이므루 최악의 경우 2^30, 즉 완전탐색으로 풀 수 없다.
어떻게 풀어야할까? 이 문제는 반으로 나눠서 각 경우의 수를 모두 구한 뒤 합이 c보다 작거나 같은지 판단해주면 된다.
rSum을 오름차순으로 정렬해줘야하는데 이는 이분탐색을 하기 위해서다.
정렬해주고 나서는 lSum[i]에 대해서 lSum[i] + rSum[j] <= c를 만족하는 j를 찾으면 된다.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c, arr[31], lSize, rSize, idx, ans;
ll lSum[33000], rSum[33000]; // 대략 2^15의 공간으로 배열을 잡아둠

void input() {
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void calculate(int i, ll sum, ll &size, ll sumArr[], bool flag) {
    if(sum > c) return;
    if(flag) {
        if(i == n / 2) {
            sumArr[size] = sum;
            size += 1;
            return;
        }
    } else {
        if(i == n) {
            sumArr[size] = sum;
            size += 1;
            return;
        }
    }
    
    calculate(i + 1, sum + arr[i], size, sumArr, flag);
    calculate(i + 1, sum, size, sumArr, flag);
}

void binarySearch(int s, int e, ll val) {
    if(s > e) return;
    int mid = (s + e) / 2;
    if(rSum[mid] + val <= c) {
        idx = mid;
        binarySearch(mid + 1, e, val);
    } else
        binarySearch(s, mid - 1, val);
}

void func() {
    calculate(0, 0, lSize, lSum, 1);
    calculate(n / 2, 0, rSize, rSum, 0);
    sort(rSum, rSum + rSize);

    for(int i = 0; i < lSize; i++) {
        idx = -1;
        binarySearch(0, rSize - 1, lSum[i]);
        ans += (idx + 1);
    }
    cout << ans;
}

int main(void) {
    input();
    func();
    return 0;
}