#include <stdio.h>

void main(void) {
    int i;
    int a[5] = {0, 1, 2, 3, 4};
    for (i=0;i<6;i++) {
        printf("%d\n", a[i]);
    }
    for (i=0;i<6;i++) {
        a[i] = i * 10;
    }
    for (i=0;i<6;i++) {
        printf("%d\n", a[i]);
    }
}