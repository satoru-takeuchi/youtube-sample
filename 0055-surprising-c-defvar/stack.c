#include <stdio.h>

void bar() {
        int i = 100;
}

void foo() {
        int i = 10;
        bar();
}

void main() {
        int i = 1;
        foo();
}
