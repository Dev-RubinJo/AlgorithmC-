#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans;
vector<int> av, bv;
int pa[1000001], pb[1000001];
map<int, int> ac, bc;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> a >> b;
    for(int i = 0; i < a; i++) {
        int t; cin >> t;
        av.push_back(t);
    }
    av.insert(av.end(), av.begin(), av.end());
    for(int i = 1; i < av.size(); i++) 
        pa[i] = av[i] + pa[i - 1];
    
    for(int i = 0; i < b; i++) {
        int t; cin >> t;
        bv.push_back(t);
    }
    bv.insert(bv.end(), bv.begin(), bv.end());
    av.insert(av.begin(), 0); bv.insert(bv.begin(), 0);
    for(int i = 1; i < bv.size(); i++) 
        pb[i] = bv[i] + pb[i - 1];

    for(int i = 1; i <= a; i++) {
        for(int j = 0; j < a; j++) {
            ac[pa[j + i] - pa[j]] += 1;
            // cout << j + i << " : " << j << " " << pa[j + i] - pa[j] << " " << pa[j + i] << " " << pa[j]  << '\n';
            if(i == a) break;
        }
    }
    // cout << '\n';
    for(int i = 1; i <= b; i++) {
        for(int j = 0; j < b; j++) {
            bc[pb[j + i] - pb[j]] += 1;
            // cout << j + i << " : " << j << " " << pb[j + i] - pb[j] << " " << pb[j + i] << " " << pb[j]  << '\n';
            if(i == b) break;
        }
    }
    // cout << '\n';
    for(int i = 1; i < n; i++) {
        ans += ac[n - i] * bc[i];
        // cout << i << " : " << ans << '\n';
    }
    ans += ac[n];
    // cout << ans << '\n';
    ans += bc[n];
    // cout << ans << '\n';
    cout << ans;

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std; 
// int want, n, m, temp, cnt;
// int a[1001], b[1001], ret, aSum, bSum, psum_a[2002], psum_b[2002];
// map<int, int> aCnt, bCnt;
// void make(int n, int psum[], map<int, int> & _map){
//     for(int interval = 1; interval <= n; interval++){
//         for(int start = interval; start <= n + interval - 1; start++){
//             int sum = psum[start] - psum[start - interval];
//             _map[sum]++;
//             if(interval == n) break;
//         }
//     }
//     return;
// }
// int main(){
//     scanf("%d %d %d", &want, &n, &m);
//     for(int i = 1; i <= n; i++){
//         scanf("%d", a + i); psum_a[i] = psum_a[i - 1] + a[i];
//     }
//     for(int i = n + 1; i <= 2 * n; i++) psum_a[i] = psum_a[i - 1] + a[i - n];
//     for(int i = 1; i <= m; i++){
//         scanf("%d", b + i);
//         psum_b[i] = psum_b[i - 1] + b[i];
//     }
//     for(int i = m + 1; i <= 2 * m; i++)psum_b[i] = psum_b[i - 1] + b[i - m];

//    make(n, psum_a, aCnt);
//    make(m, psum_b, bCnt);



//    int sum =0;


//    for(int i=1; i<want; i++) {
//        sum += aCnt[want - i] * bCnt[i];
//    }
//    sum += aCnt[want];
//    sum += bCnt[want];

//    cout<<sum<<"\n";





// }