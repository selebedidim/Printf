#include "main.h"
/******** POINTER TO BE PRINTED ********/
/**
 * print_pointer - print the value of a pointer variable
 * @types:a list of arguments containing the pointer variable to be printed
 * @buffer:an array  used as a buffer to facilitate the printing process
 * @flags:a structure responsible for computing and storing active formatting flags
 * @width:the width of the output field for formatting the pointer value
 * @precision:a specification that determines the level of precision for formatting
 * @size:a size specifier indicating the size of the pointer variable
 *
 * Return:number of number characters printed
 */
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char extra_c = 0; padd = '';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addres;
	char map_to[] = "0123456789abcdef";
	void *addres = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addres == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addres = (unsigned long)addres;

	while (num_addres > 0)
	{
		buffer[ind--] = map_to[num_addres % 16];
		num_addres /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = '', length++;
	ind++;

	return (write_pointer(buffer, ind, length, width, flags, padd, extra_c, padd_start));
}
/******** PRINT NON PRINTABLE ********/
/**
 * print_non_printable - print ASCII codes in hexadecimal format for non-printable characters
 * @types:a list of arguments containing the non-printable characters to be printed
 * @buffer:an array used as a buffer to facilitate the printing process
 * @flags:a structure responsible for computing and storing active formatting flags
 * @width:the width of the output for formatting the hexadecimal codes
 * @precision:a specification that determines the level of precision for formatting
 * @size:a size specifier indicating the size of the non-printable character data
 *
 * Return:number of  chars printed
 */
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;

	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str([i]))
				buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;

	}
	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
/******** PRINT REVERSE ********/
/**
 * print_reverse - print a reverse string
 * @types: a list of arguments containing the string to be printed in reverse
 * @buffer:an array used as a buffer to facilitate the printing process
 * @flags:a structure responsible for computing and storing active formatting flags
 * @width:the width of the output field for formatting the reversed string
 * @precision:a specification that determines the level of precision for formatting
 * @size:a size specifier indicating the size of the string data
 *
 * Return:numbers of characterss printed
 */
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = ("NULL");
	}
	for (i = 0; str[i]; i++)

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];
		write(1, &z, 1);
		count++;
	}
	return (count);
}
/******** PRINT A STRING IN ROT13 ********/
/**
 * print_rot13string - print a string encoded in rot13
 * @types:a list of arguments containing the string to be printed in rot13 encoding
 * @buffer:an array used as a buffer to facilitate the printing process
 * @flags:a structure responsible for computing and storing active formatting flags
 * @width:the width of the output field for formatting the rot13 encoded string
 * @precision:a specification that determines the level of precision for formatting
 * @size:a size specifier indicating the size of the string data
 *
 * Return:numbers of characters printed
 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] =
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghiklmnopqrstuvwxyz";
	char out[] =
	"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghiklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
