#include "main.h"

/**
 * print_hex - Outputs a number in hexadecimal base,using lowercases characters
 * @l:The va_list containing argument from the printf function.
 * @f:A pointer to the struct flags, which specifies any flags passed to _printf.
 * Description:This function invokes the convert() function, which converts the input
 * number into the appropriate base and returns it as a string
 *
 * Return:The number of characters printed
 */
int print_hex(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 1);
	int count = 0;

	if (f->hash == l && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);
	return (count);
}

/**
 * print_hex_upp - Outputs a number in hexadecimal base using uppercase characters
 * @l:The va_list containing arguments from the _printf function.
 * @f:A pointer to the struct flags, which specifies any flags passed to printf
 *
 * Descriptive:This function utilizes the convert() function to convert the input
 * number into the appropriate hexadecimal format and returns it as a string
 *
 * Return:The number of characters printed
 */
int print_hex_upp(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0X");
	count += _puts(str);
	return (count);
}

/**
 * print_binary - Outputs a number in binary base (base 2)
 * @l:The va_list containing arguments from the _printf function.
 * @f:A pointer to the struct flags that speficies any flags passed to printf
 *
 * Descriptive:This function invokes the convert() function to transform the input
 * number into the binary format and returns it as a string
 *
 * Return:The number of characters printed
 */
int print_binary(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 2, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_octal - Output a number in octal base (base 8)
 * @l:The va_list containing arguments from the _printf function.
 * @f:A pointer to the struct flags that specifies any flags passed to _printf.
 *
 * Description:This function utilizes the convert() function to convert the input
 * number into the octal format and returns it as a string
 *
 * Return:The number of characters printed
 */
int print_octal(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 8, 0);

	count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);
	return (count);
}
