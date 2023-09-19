#include "main.h"

int main() {
    int count = _printf("Hello, %s! This is a %c example.%%\n", "world", 'C');
    printf("\nTotal characters printed: %d\n", count);
    return 0;
}
