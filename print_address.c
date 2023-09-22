#include "main.h"

/**
 * print_addr - Output the hexadecimal representation of a given address
 * @l:The va_list containing arguments from the _printf function
 * @f:A pointer to the struct flags, which specifies any flags passed to _printf.
 *
 * Return:The number of characters printed
 */
int print_addr(va_li l, flags_t *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
				return (_puts("(nil)"));
	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);

	return (count);
}
