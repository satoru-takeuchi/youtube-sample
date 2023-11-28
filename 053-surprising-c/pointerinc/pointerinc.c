#include <stdio.h>

void main(int argc, char *argv[]) {
    int a = 1, b = 2;
    int *p = &a;
    *p = 10;
    p++;
    *p = 20;
    printf("%d, %d\n", a, b);
}