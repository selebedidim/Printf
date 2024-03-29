#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf -Printf()
 * @format:format
 *
 * Return:printed chars
 */
int _printf(const char *format, ...)
{
	int i;
	int print = 0;
	int print_chars = 0;
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
			print_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			i++;

			print = handle_print(format, &i, list, buffer, flags, width, precision, size);
			if (print == -1)
				return (-1);
			print_chars += print;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (print_chars);
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer:Array of chars
 * @buff_ind:index at which to add next char
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
