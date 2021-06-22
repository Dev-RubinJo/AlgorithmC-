#include <bits/stdc++.h>
using namespace std;
#define y1 oxoxox1
int x1, y1, x2, y2, r1, r2, tc;
int main(void) {
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
        if(r1 + r2 < d)
            cout << 0 << '\n';
        else if(abs(r1 - r2) > d)
            cout << 0 << '\n';
        else if(d == 0 && r1 == r2)
            cout << -1 << '\n';
        else if(d == abs(r1 + r2)) 
            cout << 1 << '\n';
        else if(d == abs(r1 - r2))
            cout << 1 << '\n';
        else 
            cout << 2 << '\n';
    }
    return 0;
}