#include "holberton.h"

/**
 * _printf - prints arguements passed to it
 * @format: list of arguements that ccan be passed
 * Return: a string
 */
int _printf(const char *format, ...)
{
	va_list list;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int id = 0;
	unsigned int length = 0;

	flags_t flags[] = {
		{"c", character},
		{"s", string},
		{NULL, NULL},
	};

	va_start(list, format);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			while (flags[j].f_arg)
			{
				if (format[i + 1] == flags[j].flags[0])
				{
					length += flags[j].f_arg(list);
					id = 1;
					i++;
				}
				j++;
			}
			if (id == 0)
			{
				_putchar(format[i]);
				length += 1;
			}
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			i++;
			length += 1;
		}
		else
		{
			_putchar(format[i]);
			length += 1;
		}
		i++;
	}

	va_end(list);

	return (length);
}
