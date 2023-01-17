#include <stdio.h>

void foo(void) {
        int i = 200;
}

void bar(void) {
        int i;
        printf("%d\n", i);
}

int main(void) {
        foo();
        bar();
}
