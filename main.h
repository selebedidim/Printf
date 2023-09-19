#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int handle_print(const char *format, int *i, va_list list, char *buffer, int *buff_ind);
/* functions1.c prototypes*/
int print_hexa(va_list lists, char map[], buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_hexa_upper(va_list lists, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list lists, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list lists, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list lists, char buffer[], int flags, int width, int precision, int size);

#include <stdarg.h>

int _printf(const char *format, ...);

#endif  /* MAIN_H */
