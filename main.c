#include <stdio.h>
#include "my_printf.h"

int main() {
    int count;

    count = _printf("The answer is %d.\n", 42);
    printf("Characters printed: %d\n", count);

    count = _printf("Value of pi is approximately %d.\n", 3);
    printf("Characters printed: %d\n", count);

    return 0;
}
