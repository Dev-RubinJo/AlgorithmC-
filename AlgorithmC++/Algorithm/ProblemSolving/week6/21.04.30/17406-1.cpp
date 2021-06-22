#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans = INT_MAX, r, c, s;
int a[101][101], aa[101][101];
// int ro[7][3];
vector<tuple<int, int, int>> ro;
bool v[7];
void rotate(int r, int c, int s) {
    int temp[101][101] = {0, };
    int si = r - s - 1, sj = c - s - 1, ei = r + s, ej = c + s;
    int termi = si + ei, termj = sj + ej;
    while(si <= ei && sj  <= ej) {
        // cout << "si: " << si << " sj: " << sj << " ei: " << ei << " ej: " << ej << '\n';
        for(int i = si; i < ei; i++) {
            if(i == si) {
                for(int j = sj; j < ej - 1; j++) {
                    temp[i][j + 1] = aa[i][j];
                }
            } else if(i == ei - 1) {
                for(int j = sj; j < ej - 1; j++) {
                    temp[i][j] = aa[i][j + 1];
                }
                temp[i - 1][sj] = aa[i][sj];
                temp[i][ej - 1] = aa[i - 1][ej - 1];
            } else {
                temp[i - 1][sj] = aa[i][sj];
                temp[i][ej - 1] = aa[i - 1][ej - 1];
            }
        }
        if(termi % 2 && termj % 2) {
            temp[termi / 2][termj / 2] = aa[termi / 2][termj / 2];
        }
        si += 1; sj += 1; ei -= 1; ej -= 1;
    }
    // for(int i = r - s - 1; i < r + s; i++) {
    //     for(int j = c - s - 1; j < c + s; j++) {
    //         cout << temp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    for(int i = r - s - 1; i < r + s; i++) {
        for(int j = c - s - 1; j < c + s; j++) {
            aa[i][j] = temp[i][j];
        }
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
}
// void func(int cnt) {
//     if(cnt == k) {
//         for(int i = 0; i < n; i++) {
//             int sum = 0;
//             for(int j = 0; j < m; j++) {
//                 sum += aa[i][j];
//             }
//             ans = min(sum, ans);
//         }
//         return;
//     }
//     for(int i = 0; i < k; i++) {
//         if(v[i]) continue;
//         v[i] = 1;
//         // cout << i << '\n';
//         rotate(ro[i][0], ro[i][1], ro[i][2]);
//         func(cnt + 1);
//         v[i] = 0;
//     }
// }
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            cin >> a[i][j];
        
    for(int i = 0; i < k; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        ro.push_back(make_tuple(r, c, s));
    }

	do {
		for (int i = 0; i < k; i++) {
			tuple<int, int, int> tmp = ro[i];
			int y = get<0>(tmp);
			int x = get<1>(tmp);
			int s = get<2>(tmp);
			//cout << y << x << s << endl;
		}
		//cout << endl;
	} while (next_permutation(ro.begin(), ro.end()));

    do {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                aa[i][j] = a[i][j];
            }
        }
        for(int i = 0; i < k; i++) {
            int r, c, s;
            tie(r, c, s) = ro[i];
            rotate(r, c, s);
        }
            
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < m; j++) {
                sum += aa[i][j];
            }
            ans = min(sum, ans);
        }
    } while(next_permutation(ro.begin(), ro.end()));
    // for(int i = 0; i < k; i++) {
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < m; j++) {
    //             aa[i][j] = a[i][j];
    //         }
    //     }
    //     v[i] = 1;
    //     // cout << i << "\n";
    //     rotate(ro[i][0], ro[i][1], ro[i][2]);
    //     func(1);
    //     v[i] = 0;
    //     // cout << '\n';
    // }
    
    cout << ans;
    return 0;
}