#include "main.h"

/**
 * print_string - Iterates through a string and prints each character
 * @l:The va_list containing arguments from the _printf function.
 * @f:A pointer to the struct flags, which specifies any flags passed to _printf.
 *
 * Return:The number of characters printed
 */
int print_string(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * print_char - Outputs a single character.
 * @l:The va_list containing arguments from the _printf function
 * @f:A pointer to the struct flags,which specifiers any flags passed to _printf
 *
 * Return:The number of characters printed
 */
int print_char(va_list l, flags_t *f)
{
	(void)f;
	_putchar(va_arg(l, int));
	return (1);

