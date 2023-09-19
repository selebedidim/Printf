#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @lists:list of arguments
 * @buffer:buffer array to handle printf
 * @flags:calculates active flags
 * @width:get width
 * @precision:precision specification
 * @size:size specifier
 *
 * Return:number of characters printed
 */
int print_unsigned(va_list lists, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(lists, unsigned long int);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_octal - prints an unsigned number in octal notation
 * @lists:list of arguments
 * @buffer:buffer array to handle print
 * @flags:calculates active flags
 * @width:get width
 * @precision:precision specification
 * @size:size specifier
 *
 * Return:number of characters printed
 */
int print_octal(va_list lists, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(lists, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num  = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @lists:list of arguments
 * @buffer:buffer array to handle print
 * @width:get width
 * @precision:precision specification
 * @size:size specifier
 *
 * Return:number of characters printed
 */
int print_hexadecimal(va_list lists, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(lists, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - prints an unsigned number in uppercase hexadecimal notation
 * @lists:list of arguments
 * @buffer:buffer array to handle print
 * @flags:calculate active flags
 * @width:get width
 * @precision:precision specification
 * @size:size specifier
 *
 * Return:number of characters printed
 */
int print_hexa_upper(va_list lists, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(lists, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}
/**
 * print_hexa - prints a hexadecimal number in lowercases or uppercases
 * @lists - list of arguments
 * @map_to:array of values to map the number to
 * @flags:calculate active flags
 * @flags_ch:calculate active flags
 * @width:get width
 * @precision:precision specification
 * @size:size specifier
 * @size:size specification
 *
 * Return:number of characters printed
 */
int print_hexa(va_list lists, char map[], buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(lists, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));

}
