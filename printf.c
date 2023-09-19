#include "main.h"
<<<<<<< HEAD
#include <stdarg.h>
#include <unistd.h>
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_handle(const char *format, int *i, va_list list, char *buffer, int *buff_ind);


void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 * *Format - To print using printf
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
=======
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
>>>>>>> 825253ca5a04e853863e91bcd016d60fedf424d7
}
