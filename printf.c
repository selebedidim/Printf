/*
 * Printf -Function print via pring
 * Strlen - No of letters
 *
 */

#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) 
{
    va_list args;
    va_start(args, format);

    int char_count = 0;
    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'
            if (*format == '\0') break; // Handle format string ending with '%'
            if (*format == 'c') {
                int c = va_arg(args, int);
                putchar(c);
                char_count++;
            } else if (*format == 's') {
                char *s = va_arg(args, char *);
                while (*s != '\0') {
                    putchar(*s);
                    s++;
                    char_count++;
                }
            } else if (*format == '%') {
                putchar('%');
                char_count++;
            }
        } else {
            putchar(*format);
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count;
}
