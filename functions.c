#include "main.h"

/**** print_char ****/
/**
 * print_char - prints a char
 * @types:list of arguments
 * @buffer:buffer array to handle print
 * @flags:calculates active flags
 * @width:width
 * @precision:precision specification
 * @size:size specifier
 * Description:this function is responsible for printing a single character.it takes
 * multiple arguments, including a list of types, a buffer array for handling the print,
 * flags for calculating active flags,the width of the characters,precision specification,
 * and a size specifier.
 * Return:number of chars printed
 */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**** print_string ****/
/**
 * print_string - prints a string
 * @types:list of arguments
 * @buffer:buffer array to handle print
 * @flags:calculates active flags
 * @width:get width
 * @precision:precision specifier
 * @size:size specifier
 * Description:this function is designed for printing a string of characters.it takes
 * parameters,including a list of argument types,a buffer array used for n=managing the
 * print process,the calculation of active flags through the flags parameter,retrieval of
 * width using width,specification of precision with precision,and a size specifier indicated
 * by size.
 * Return:Number of chars printed
 */
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}
	while (str[len] != '\0')
		len++;
	if (precisio >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}

 /**** print_percent ****/
/**
 * print_percent - prints a percent sign
 * @types:list of arguments
 * @buffer:buffer array to handle print
 * @flags:calculates active flags
 * @width:get width
 * @precision:precision specification
 * @size:size specifier
 * Description:this function is responsible for printing a percent sign
 * character.it accepts several parameters, including a list of arguments
 * types,a buffer array used for print management,the calculation of active
 * flags via the flags parameters ,retrieval of width using width,specification
 * of precision through precision and a size specifier indicated by size.
 * Return:the number of chars printed
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**** print_int ****/
/**
 * print_int -print integer
 * types:list of arguments
 * @buffer:buffer array to handle print
 * @flags:calculates active flags
 * @width:get width
 * @precision:precision specification
 * @size:size specifier
 * Description:thi s function is designed for printing integer values.it accept several
 * parameters,including a list of argument types,a buffer array used to manage the print
 * operation,the calculation of active flags via the flags parameter,retrieval of width
 * using width ,specification of precision through precision,and a size specifier indicated
 * by size
 *
 * Return:Number of chars printed
 */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_size - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '\0';
	num = (unsigned long int n);

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] == (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/**** print_binary ****/

/**
 * print_binary - prints an unsigned number
 * @types:list of arguments
 * @buffer:buffer array to handle print
 * @flags:calculates active flags
 * @width:get width
 * @precision:precision specification
 * @size:size specifier
 * Description:this function is intendedfor printing unsigned numerical values in binary
 * format.it accepts various parameters,including a list of argument types, a buffer array
 * utilized for management,the computation of active flags via the flags parameter retrieval
 * of width using width,specification of precision through precision and a size specifier
 * indicated by size.
 *
 * Return:Number of char printed
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned  int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0; sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
		}
	}
	return (count);
}
