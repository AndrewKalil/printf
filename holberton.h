#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdard.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _putchar(char c);
int character(va_list ap);
int string(va_list ap);
int decimal(va_list ap);
int integer(va_list ap);

typedef struct list
{
	char *arg;
	int (*f_arg)();
} _printf;

#endif
