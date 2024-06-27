#include <stdio.h>
#include "sum.h"
// #include <unistd.h>

int main() {
    // sleep(50);

    int a = add(2, 3);
    printf("%d\n", a);
    int b = minus(2, 3);
    printf("%d\n", b);
}