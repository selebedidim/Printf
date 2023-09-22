#include "main.h"

/**
 * _printf - Generates output with a specified format.
 * @format:A format string that includes characters and conversion specifiers.
 *
 * Description:This function delegates the task of selecting the appropriate printing function
 * based on the conversion specifiers found in the format string to get_print() function
 *
 * Return:The length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p);
					p++;
					pfunc = get_print(*p);
					count += (pfunc)
					? pfunc(arguments, &flags)
					: _printf("%%%c", *p);
		} else
					count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}
