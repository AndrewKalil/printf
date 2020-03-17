#include "holberton.h"

/**
 * mini_printf - returns string for _printf
 * @format: list of arguements that ccan be passed
 * @_list_: contains a list of arguements that will be passed
 * @_flags_: struct pointer
 * Return: a string
 */
int mini_printf(const char *format, va_list _list_, flags_t *_flags_)
{
	int i = 0, j = 0, length = 0;

	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%' && (format[i + 1] != '%' || format[i + 1] == ' '))
		{
			if (format[i + 1] == ' ')
			{
				while (format[i + 1] == ' ')
				i++;
			}
			while (j < 4)
			{
				if (format[i + 1] == _flags_[j].flags[0])
				{
					length += _flags_[j].f_arg(_list_);
					i++;
					break;
				} j++;
			}
			if (j == 4)
				length += print_c(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			length += print_c('%');
			i++;
		}
		else
		{
			length += print_c(format[i]);
		} i++, j = 0;
	}
	return (length);
}

/**
 * _printf - prints arguements passed to the standard output
 * @format: list of arguements
 * Return: length of string
 */
int _printf(const char *format, ...)
{
	va_list list;
	int length = 0;

	flags_t flags[] = {
		{"c", character},
		{"s", string},
		{"d", decimal_integer},
		{"i", decimal_integer}
	};

	if (format == NULL)
		return (-1);
	va_start(list, format);

	length = mini_printf(format, list, flags);
	va_end(list);
	return (length);
}
