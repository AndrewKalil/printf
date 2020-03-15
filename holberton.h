#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _putchar(char c);
int character(va_list ap);
int string(va_list ap);
int decimal(va_list ap);
int integer(va_list ap);

/**
 * struct list - struct for conversion specifiers
 * @arg: specifier
 * @f_arg: function for specifier
 */
typedef struct flags
{
	char *flags;
	int (*f_arg)();
} flags_t;

#endif
