#include "printf.h"
#include <stdio.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // To keep track of the number of characters printed

    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    fputs(va_arg(args, char*), stdout);
                    count += strlen(va_arg(args, char*));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    // Unsupported specifier, ignore it
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++; // Move to the next character in the format string
    }

    va_end(args);
    return count;
}
