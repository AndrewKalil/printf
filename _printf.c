#include "holberton.h"

/**
 * _printf - prints arguements passed to it
 * @format: list of arguements that ccan be passed
 * Return: a string
 */
int mini_printf(const char *format, va_list _list_, flags_t *_flags_ )
{
	int i = 0, j = 0, length = 0;

	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%' && format[i + 1] != '%')
		{
			while (j < 2)
			{
				if (format[i + 1] == _flags_[j].flags[0])
				{
					length += _flags_[j].f_arg(_list_);
					i++;
					break;
				}
				j++;
			}
				if (j == 2)
			{
				length += print_c(format[i]);
			}
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			length += print_c('%');
			i++;
		}
		else
		{
			length += print_c(format[i]);
		}
		i++;
	}
	return (length);
}

int _printf(const char *format, ...)
{
	va_list list;
	int length;

	flags_t flags[] = {
		{"c", character},
		{"s", string},
		{NULL, NULL},
	};

	if (format == NULL)
		return (-1);
	va_start(list, format);

	length = mini_printf(format, list, flags);
	va_end(list);
	return (length);
}
