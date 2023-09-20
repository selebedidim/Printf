#include "main.h"

/**
 * print_unsigned - Print an unsigned number
 * @types:list of arguments containing the number to be printed
 * @buffer:buffer array used for printing
 * @flags:flags used for calculation
 * @width:width of the printed output
 * @precision:precision specification for formatting
 * @size:size specifier for the number
 *
 * Return:number of characters printed
 */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

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
 * print_octal - print an unsigned number in octal notation
 * @types:list of arguments containing the unsigned number to be printed
 * @buffer:A character buffer array used for printing
 * @flags:A structure that calculates and stores active formattting flags
 * @width:the width of the output field
 * @precision:precision specification for formatting the octal
 * @size:size specifier indicating the size of the number
 *
 * Return:number of characters printed
 */
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
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
 * print_hexadecimal - Print an unsigned number in hexadecimal notation
 * @types:list of arguments containing the unsigned number to be printed
 * @buffer:an array used as a buffer to facilitate the printing process
 * @width:the width of the output field for formatting hexadecimal number
 * @precision:a precision specification that determines the level of precision for the formatting
 * @size:a size specifier indicating the size of the number being printed
 *
 * Return:number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - print an unsigned number in uppercase hexadecimal notation
 * @types:list of arguments containing the unsigned number to be printed
 * @buffer:an array used as a buffer to facilitate the printing process
 * @flags:a structure responsible for computing and storing active formatting flags
 * @width:the width of the output field for formatting the uppercase hexadecimal number
 * @precision:a specification that determines the level of precision for the formatting
 * @size:size specifier indicating the size of the number being printed
 *
 * Return:number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}
/**
 * print_hexa - print a hexadecimal number in lowercase or uppercase
 * @types - list of arguments containing the hexadecimal number to be printed
 * @map_to:an array of values to map the number to for formatting
 * @flags:a structure responsible for computing and storing active formatting flags
 * @flags_ch:a flag that determines whether to print in lowercase or uppercase
 * @widththe width of the output field formatting the hexadecimal number
 * @precision:a specification that determines the level of precision for formatting
 * @size:size specifier indicating the size of the number being printed
 *
 * Return:number of characters printed
 */
int print_hexa(va_list types, char map[], buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
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
