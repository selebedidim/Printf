#include "main.h"
#include <stdio.h>
#include <unistd.h>  // For the write function

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;  // Count of characters printed

    while (*format) {
        if (*format != '%') {
            // Use the write function to print characters
            write(1, format, 1);  // 1 is the file descriptor for stdout
            count++;
        } else {
            format++;  // Move past '%'
            if (*format == 'd' || *format == 'i') {
                // Handle %d and %i - integer
                int num = va_arg(args, int);  // Get the integer from args
                char buffer[20];  // Assuming a maximum of 20 characters for the integer
                int len = snprintf(buffer, sizeof(buffer), "%d", num);
                write(1, buffer, len);
                count += len;
            }
        }
        format++;
    }

    va_end(args);

    return count;
}
