#include <iostream>

using namespace std;

int main(void) {

    int n;
    double max = 0;
    double a[1000];
    double temp = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(max < a[i])
            max = a[i];
    }

    for(int i = 0; i < n; i++) {
        temp += (double)(a[i] / max) * 100;
    }

    temp = temp / 3;
        
    cout << temp;

    return 0;
}
