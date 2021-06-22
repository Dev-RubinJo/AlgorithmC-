#include <stdio.h>
bool arr[30];
int tmp, i;
int main(void) {
    for(i = 0; i < 28; i++) {
        scanf("%d", &tmp);
        arr[tmp - 1] = 1;
    }

    for(i = 0; i < 30; i++) {
        if(!arr[i]) printf("%d\n", i + 1);
    }
    return 0;
}