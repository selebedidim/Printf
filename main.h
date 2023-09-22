#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/****flags ****/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**Size **/
#define S_LONG 2
#define S_LONG 1

/**
 * struct fmt - struct op
 * @fmt:format specifier
 * @fn:the function associated
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
}

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt:the format
 * @fm_t:the function association
 */
typedef struct fmt fmt fmt_t;
int _printf(const char *format, ...);
int handle _printf(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/*** handle ***/
int handle_print(const char *fmt, int *ind, va_list list, char buffer[], int flags, int width, int precision, int size);

/*** get_width ***/
int get_width(const char *format, int *i, va_list list);

/*** get_size ***/
int get_size(const char *format, int *i);

/*** get_flags ***/
int get_flags(const char *format, int *i);

/*** get_precision ***/
int get_precision(const char *format, int *i, va_list list);

/*** functions.c ***/
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
#endif /* MAIN_H */
